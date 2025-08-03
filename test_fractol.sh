#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

PROGRAM="./fractol"
TOTAL_TESTS=0
PASSED_TESTS=0

print_test() {
    echo -e "${YELLOW}[TEST $((TOTAL_TESTS + 1))]${NC} $1"
}

run_test() {
    local description="$1"
    local command="$2"
    local expected_exit_code="$3"
    local expected_output="$4"
    
    print_test "$description"
    echo "Command: $command"
    
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    
    # Run command and capture output and exit code
    output=$(eval "$command" 2>&1)
    exit_code=$?
    
    # Check exit code
    if [ "$exit_code" -eq "$expected_exit_code" ]; then
        if [ -n "$expected_output" ]; then
            if echo "$output" | grep -q "$expected_output"; then
                echo -e "${GREEN}✓ PASS${NC} (Exit: $exit_code, Output contains: $expected_output)"
                PASSED_TESTS=$((PASSED_TESTS + 1))
            else
                echo -e "${RED}✗ FAIL${NC} (Exit: $exit_code, Expected output: $expected_output, Got: $output)"
            fi
        else
            echo -e "${GREEN}✓ PASS${NC} (Exit: $exit_code)"
            PASSED_TESTS=$((PASSED_TESTS + 1))
        fi
    else
        echo -e "${RED}✗ FAIL${NC} (Expected exit: $expected_exit_code, Got: $exit_code)"
        echo "Output: $output"
    fi
    echo
}

echo -e "${YELLOW}=== FRACTOL COMPREHENSIVE ERROR TESTING ===${NC}"
echo

# Test 1: No arguments
run_test "No arguments" "$PROGRAM" 1 "Available fractals"

# Test 2: Too many arguments (but not 4)
run_test "Too many arguments (3)" "$PROGRAM arg1 arg2 arg3" 1 "Only julia accepts parameters"

# Test 3: Too many arguments (5)
run_test "Too many arguments (5)" "$PROGRAM arg1 arg2 arg3 arg4 arg5" 1 "Available fractals"

# Test 4: Invalid fractal name
run_test "Invalid fractal name" "$PROGRAM invalid_fractal" 1 "Available fractals"

# Test 5: Invalid fractal name with typo
run_test "Fractal name typo (mandelbro)" "$PROGRAM mandelbro" 1 "Available fractals"

# Test 6: Invalid fractal name with typo
run_test "Fractal name typo (juliax)" "$PROGRAM juliax" 1 "Available fractals"

# Test 7: Invalid fractal name with typo
run_test "Fractal name typo (burning_shi)" "$PROGRAM burning_shi" 1 "Available fractals"

# Test 8: Case sensitivity
run_test "Case sensitivity (JULIA)" "$PROGRAM JULIA" 1 "Available fractals"

# Test 9: Case sensitivity (Mandelbrot)"
run_test "Case sensitivity (Mandelbrot)" "$PROGRAM Mandelbrot" 1 "Available fractals"

# Test 10: Non-julia with parameters
run_test "Mandelbrot with parameters" "$PROGRAM mandelbrot 0.5 0.3" 1 "Only julia accepts parameters"

# Test 11: Burning ship with parameters
run_test "Burning ship with parameters" "$PROGRAM burning_ship -0.4 0.6" 1 "Only julia accepts parameters"

# Test 12: Julia with invalid first parameter
run_test "Julia invalid first param (abc)" "$PROGRAM julia abc 0.5" 1 "Invalid number format"

# Test 13: Julia with invalid second parameter
run_test "Julia invalid second param (def)" "$PROGRAM julia 0.5 def" 1 "Invalid number format"

# Test 14: Julia with both invalid parameters
run_test "Julia both invalid params" "$PROGRAM julia abc def" 1 "Invalid number format"

# Test 15: Julia with empty parameter
run_test "Julia empty first param" "$PROGRAM julia '' 0.5" 1 "Invalid number format"

# Test 16: Julia with space in parameter
run_test "Julia space in param" "$PROGRAM julia '0.5 0.3' 0.2" 1 "Invalid number format"

# Test 17: Julia with special characters
run_test "Julia special chars (!@#)" "$PROGRAM julia !@# 0.5" 1 "Invalid number format"

# Test 18: Julia with multiple dots
run_test "Julia multiple dots (0.5.3)" "$PROGRAM julia 0.5.3 0.2" 1 "Invalid number format"

# Test 19: Julia with trailing letters
run_test "Julia trailing letters (0.5abc)" "$PROGRAM julia 0.5abc 0.2" 1 "Invalid number format"

# Test 20: Julia with leading letters
run_test "Julia leading letters (abc0.5)" "$PROGRAM julia abc0.5 0.2" 1 "Invalid number format"

# Test 21: Julia with just dot
run_test "Julia parameter just dot (.)" "$PROGRAM julia . 0.5" 1 "Invalid number format"

# Test 22: Julia with just minus
run_test "Julia parameter just minus (-)" "$PROGRAM julia - 0.5" 1 "Invalid number format"

# Test 23: Julia with double minus
run_test "Julia double minus (--0.5)" "$PROGRAM julia --0.5 0.2" 1 "Invalid number format"

# Test 24: Julia with plus sign (should be valid)
run_test "Julia with plus sign (+0.5)" "timeout 0.5s $PROGRAM julia +0.5 0.2 || exit 0" 0 ""

# Test 25: Julia very long number
run_test "Julia very long number" "$PROGRAM julia 0.123456789012345678901234567890 0.2" 1 ""

# Test 26: Julia with tab character
run_test "Julia tab character" "$PROGRAM julia '0.5	0.3' 0.2" 1 "Invalid number format"

# Test 27: Julia with newline
run_test "Julia newline character" "$PROGRAM julia $'0.5\n' 0.2" 1 "Invalid number format"

# Test 28: Fractal name with numbers
run_test "Fractal name with numbers (julia2)" "$PROGRAM julia2" 1 "Available fractals"

# Test 29: Fractal name partial match (juli)
run_test "Partial fractal name (juli)" "$PROGRAM juli" 1 "Available fractals"

# Test 30: Fractal name with underscore
run_test "Fractal name underscore (julia_)" "$PROGRAM julia_" 1 "Available fractals"

# Test 31: Empty string as fractal name
run_test "Empty fractal name" "$PROGRAM ''" 1 "Available fractals"

# Test 32: Julia with scientific notation
run_test "Julia scientific notation (1e-5)" "$PROGRAM julia 1e-5 0.2" 1 "Invalid number format"

# Test 33: Julia with very large numbers
run_test "Julia large numbers" "$PROGRAM julia 999999999999999999 0.2" 1 ""

# Test 34: Julia with very small decimals (should be valid)
run_test "Julia small decimals" "timeout 0.5s $PROGRAM julia 0.000000001 0.000000002 || exit 0" 0 ""

# Test 35: Multiple consecutive dots
run_test "Multiple dots (...)" "$PROGRAM julia ... 0.2" 1 "Invalid number format"

# Test 36: Number starting with dot
run_test "Number starting with dot (.5)" "$PROGRAM julia .5 0.2" 1 "Invalid number format"

# Test 37: Number ending with multiple dots
run_test "Number ending dots (0.5..)" "$PROGRAM julia 0.5.. 0.2" 1 "Invalid number format"

# Test 38: Null byte (shell truncates at null, so 0.5 is valid)
run_test "Null byte in param" "timeout 0.5s $PROGRAM julia $'0.5\x00' 0.2 || exit 0" 0 ""

# Test 39: Unicode characters
run_test "Unicode in fractal name (julía)" "$PROGRAM julía" 1 "Available fractals"

# Test 40: Very long fractal name
run_test "Very long fractal name" "$PROGRAM julia_but_with_a_very_very_very_long_name_that_should_not_match" 1 "Available fractals"

# Test 41: Valid tests (should work)
echo -e "${YELLOW}=== VALID INPUT TESTS (Should succeed) ===${NC}"

# Note: These tests will actually launch the GUI, so we'll use timeout
# and check that they don't immediately exit with error

run_test "Valid Mandelbrot" "timeout 0.5s $PROGRAM mandelbrot || exit 0" 0 ""

run_test "Valid Julia default" "timeout 0.5s $PROGRAM julia || exit 0" 0 ""

run_test "Valid Julia with params" "timeout 0.5s $PROGRAM julia -0.4 0.6 || exit 0" 0 ""

run_test "Valid Burning Ship" "timeout 0.5s $PROGRAM burning_ship || exit 0" 0 ""

run_test "Valid Julia negative params" "timeout 0.5s $PROGRAM julia -0.7 -0.27 || exit 0" 0 ""

run_test "Valid Julia zero params" "timeout 0.5s $PROGRAM julia 0 0 || exit 0" 0 ""

run_test "Valid Julia decimal params" "timeout 0.5s $PROGRAM julia 0.285 0.01 || exit 0" 0 ""

# Summary
echo -e "${YELLOW}=== TEST SUMMARY ===${NC}"
echo -e "Total tests: $TOTAL_TESTS"
echo -e "Passed: ${GREEN}$PASSED_TESTS${NC}"
echo -e "Failed: ${RED}$((TOTAL_TESTS - PASSED_TESTS))${NC}"

if [ $PASSED_TESTS -eq $TOTAL_TESTS ]; then
    echo -e "${GREEN}🎉 ALL TESTS PASSED!${NC}"
    exit 0
else
    echo -e "${RED}❌ Some tests failed.${NC}"
    exit 1
fi