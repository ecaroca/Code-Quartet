# ⚙️ Code-Quartet
El proyecto aborda la dificultad de aprender métodos numéricos de forma práctica, proponiendo una aplicación educativa interactiva que permita resolver problemas, graficar conceptos y configurar parámetros de manera intuitiva. Será multiplataforma (Windows y Linux), fácil de instalar y orientada a un aprendizaje visual, accesible y riguroso.

## 📍 Descripción del proyecto
Este proyecto implementa una **suite matemática en C/C++** que permite resolver operaciones básicas y avanzadas:
- Calculadora de operaciones elementales.  
- Operaciones con matrices (suma, multiplicación, determinante, inversa, resolver `Ax=b`).  
- Cálculo de **límites, derivadas e integrales** por métodos numéricos.  
- Resolución de **ecuaciones y sistemas no lineales**.  
- Representación de funciones mediante **gráficos ASCII** en consola.

## 📍 Objetivo General del proyecto:
- Potenciar  la autonomía de los estudiantes de enseñanza media con respecto a la resolución de problemas, ejercicios y métodos matemáticos tanto básicos, como de mayor complejidad, adquiriendo un mayor conocimiento de la materia relacionada.

## 📍 Objetivos Específicos:
- Crear un prototipo en código que entregue un menú con opciones de las operaciones que desea realizar el usuario.
  
- Implementar en código, operaciones básicas, límites, derivadas, integrales y matrices, para que el usuario desde el menú, escoja la operación a realizar.
 
- Diseñar una función que permita graficar algunas funciones y que el usuario escoja desde el menú las que están disponibles para graficar.

## 📍 Roles de los Integrantes:
- **Esteban Caroca Sánchez**: Programador/Documentación
- **Acza Riffo Jamett**: Estructura del proyecto(interfaz)/Documentación
- **Sebastián Sanchez**: Tester del programa
- **Maximiliano Lazo**:  Encargado del repositorio Github

# 📍 Descripción de las funcionalidades:
## Suite Matemática en C (Consola)

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

## ✍️ Notas técnicas
- Las rutinas de **matrices** usan eliminación Gaussiana con pivoteo parcial (determinante, resolver `Ax=b`) y Gauss‑Jordan (inversa).
- **Límites**: evalúan `f(a±h)` con pasos decrecientes hasta estabilizar.
- **Derivadas**: diferencias finitas centrales `f'(x0) ≈ (f(x0+h)-f(x0-h))/(2h)`.
- **Integrales**: Simpson compuesto con `n` subintervalos **pares**.
- **Raíces**: bisección (requiere cambio de signo) y Newton (derivada numérica).
- **Sistemas 2x2**: dos sistemas de ejemplo con Jacobiano analítico.
- **Gráficos ASCII**: malla `width x height` (por defecto 80x25) con ejes si el rango incluye 0.

## 💡 Registro de Cambios
- No  se han hecho cambios en el código hasta la fecha.

# 📍 Avances hasta la fecha:
El desarrollo de la suite matemática se encuentra en un estado **avanzado y funcional**. A la fecha, se han completado e integrado exitosamente los siguientes módulos:

### 🧮 Calculadora Básica (`calculator.c`)
- Operaciones aritméticas fundamentales: suma, resta, multiplicación y división.
- Cálculo de potencias y raíz cuadrada.
- Integrado al menú principal con manejo básico de errores (división por cero, raíz de número negativo).

### 📊 Operaciones con Matrices (`matrix.c`)
- Creación, liberación de memoria y manejo de estructuras `Matrix` y `Vector`.
- Lectura e impresión de matrices y vectores desde la consola.
- Implementación de operaciones algebraicas: Suma y multiplicación de matrices.
- **Operaciones avanzadas:** Cálculo del determinante, obtención de la matriz inversa y resolución de sistemas de ecuaciones lineales **Ax = b** mediante eliminación gaussiana con pivotaje parcial.

### 📐 Cálculo Numérico (`calculus.c`)
- Cálculo aproximado de **Límites** por izquierda y derecha.
- **Derivación numérica** utilizando el método de la diferencia central.
- **Integración numérica** mediante la Regla de Simpson compuesta.

### 🟰 Resolución de Ecuaciones (`equations.c`)
- Búsqueda de raíces de ecuaciones no lineales con una variable:
  - **Método de Bisección**
  - **Método de Newton-Raphson** (con derivada numérica)
- Resolución de **sistemas de ecuaciones no lineales (2x2)** mediante el método de Newton para sistemas. Se incluyen dos sistemas predefinidos para pruebas.

### 📈 Gráficos ASCII (`plot.c`)
- Visualización de funciones en el dominio de la terminal.
- Generación de gráficos con ejes coordenados y puntos representados por asteriscos `*`.
- Personalización del rango de visualización (`xmin`, `xmax`) y tamaño del gráfico.

### 🔧 Catálogo de Funciones (`functions.c`)
- Biblioteca central con 6 funciones predefinidas para evaluar (`sin(x)`, `cos(x)`, `exp(x)`, `ln(x)`, `x²`, `x³-x-2`).
- Manejo de errores (ej: devuelve `NAN` para `ln(x)` donde `x <= 0`).

### 🎛️ Menú Principal e Integración (`main.c`)
- Interfaz de consola interactiva y amigable.
- Integración completa de todos los módulos mediante un sistema de menús jerárquicos.
- Flujo robusto con manejo de entradas incorrectas y pausas para mejorar la experiencia de usuario.

**El proyecto es completamente funcional y puede ser compilado y utilizado para realizar las operaciones matemáticas descritas.**

## Extensiones sugeridas
- Agregar parser de expresiones (por ejemplo, `muparser` u otro) para funciones arbitrarias.
- Exportar datos (`x,f(x)`) a CSV y graficar con `gnuplot`.
- Añadir más sistemas 2x2 a la librería.
- Soporte para matrices grandes mediante archivos.

## Licencia
MIT

## 📍 Pasos próximos (Hito 2):
- Diseñar una interfaz para el programa (QT) y que este permita al usuario un uso más fluido de las operaciones disponibles.

## 📍 Anexos/Referencias
### 📖 Referencias Bibliográficas
- Las siguientes referencias bibliográficas fueron utilizadas tanto como para tener una mejor idea sobre cómo hacer los prompts, como para "alimentar" a la IA sobre las distintas operaciones matemáticas que se querían realizar en código, facilitando así, las creación de estos"

- *Métodos Numéricos: Teoría, práctica y aplicaciones (2da Edición) - Antonio Huerta Cerezuela*
  
- *Numerical Analysis (9na Edición) - Richard L. Burden y J. Douglas Faires* (este libro si bien sé encontró en español(7ma edición) no se veía muy bien, por lo tanto se utilizó esta versión en inglés)
  
- *Programación en C: Metodología, algoritmos y estructura de datos - Luis Joyanes Aguilar y Ignacio Zahonero Martinez.*
