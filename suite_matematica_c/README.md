# Suite Matemática en C (Consola)

Herramienta educativa en C que permite:
- **Calculadora** básica.
- **Matrices**: suma, multiplicación, determinante, inversa, resolver `Ax=b`.
- **Límites** (aprox. numérica unilaterales y bilateral si corresponde).
- **Derivadas** (diferencias centrales).
- **Integrales** (Simpson compuesto).
- **Ecuaciones** `f(x)=0` (bisección y Newton).
- **Sistemas no lineales** (2x2) con Newton (2 ejemplos precargados).
- **Gráficos ASCII** de `f(x)` en un rango.

> Todo funciona en **consola** (terminal) y sólo requiere `gcc` y `libm` (math).

## Compilación

```bash
make
# generará el binario ./math_suite
```

Ó, sin Makefile:
```bash
gcc -O2 -std=c11 -Wall -Wextra -Isrc -Iinclude \
  src/main.c src/calculator.c src/matrix.c src/calculus.c src/equations.c src/plot.c src/functions.c \
  -lm -o math_suite
```

## Ejecución

```bash
./math_suite
```

## Navegación del Menú

```
1) Calculadora
2) Matrices
3) Límites
4) Derivadas
5) Integrales
6) Ecuaciones (f(x)=0)
7) Sistemas no lineales (2x2)
8) Gráficos ASCII de f(x)
0) Salir
```

En las opciones que requieren una función `f(x)`, podrás elegir entre:
1. `sin(x)`  
2. `cos(x)`  
3. `exp(x)`  
4. `ln(x)` (dominio: `x>0`)  
5. `x^2`  
6. `x^3 - x - 2`  

## Notas técnicas
- Las rutinas de **matrices** usan eliminación Gaussiana con pivoteo parcial (determinante, resolver `Ax=b`) y Gauss‑Jordan (inversa).
- **Límites**: evalúan `f(a±h)` con pasos decrecientes hasta estabilizar.
- **Derivadas**: diferencias finitas centrales `f'(x0) ≈ (f(x0+h)-f(x0-h))/(2h)`.
- **Integrales**: Simpson compuesto con `n` subintervalos **pares**.
- **Raíces**: bisección (requiere cambio de signo) y Newton (derivada numérica).
- **Sistemas 2x2**: dos sistemas de ejemplo con Jacobiano analítico.
- **Gráficos ASCII**: malla `width x height` (por defecto 80x25) con ejes si el rango incluye 0.

## Extensiones sugeridas
- Agregar parser de expresiones (por ejemplo, `muparser` u otro) para funciones arbitrarias.
- Exportar datos (`x,f(x)`) a CSV y graficar con `gnuplot`.
- Añadir más sistemas 2x2 a la librería.
- Soporte para matrices grandes mediante archivos.

## Licencia
MIT