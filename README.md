# ❄️ fract-ol - Explorateur de Fractales

## 📖 Description
Le projet **fract-ol** est une immersion dans l'univers des graphiques par ordinateur. L'objectif est de générer des ensembles fractals (Mandelbrot, Julia, etc.) en temps réel en utilisant la bibliothèque **MiniLibX**. Ce projet permet de manipuler les nombres complexes et d'optimiser le rendu via des algorithmes itératifs.

---

## 🛠️ Installation & Compilation

### Prérequis
* Un compilateur (`gcc` ou `clang`).
* La bibliothèque **MiniLibX** (configurée pour Linux ou MacOS).
* `make`.

### Instructions
```bash
# Cloner le projet
git clone [https://github.com/cafabre/fractol.git](https://github.com/cafabre/fractol.git)
cd fract-ol

# Compiler le projet
make

# Pour Mandelbrot
./fractol mandelbrot

# Pour Julia (nécessite deux paramètres complexes)
./fractol julia -0.4 0.6