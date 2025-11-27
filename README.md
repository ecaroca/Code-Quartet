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

## Ejecución
- **1.** Se descargar la carpeta zip del Github
- **2.** Extraer archivo zip
- **3.** Abrir en visual studio la carpeta llamada suite_matematica_c
- **4.** En el terminal ejecutar con el comando ./math_suite
- **5.** En caso de permiso denegado del programa, utilizar comando: chmod +x math_suite.
- **6.** Luego nuevamente ./math_suite



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
## Prueba ejemplo Menú
![Menú](https://github.com/ecaroca/Code-Quartet/blob/main/IMG-20250912-WA0021%5B1%5D.jpg)

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


# 📍Hito 2: Considerar esta carpeta "Code-Quartet-class-c++"
### 🔎 Cambios estructurales
- Traducción de código C a C++
- Cambio de funciones de C struct a objets en C++ 
- Los headers cambiamos math.h por cmath, stdio.h por cstdio, ya que esto nos da acceso a las versiones C++ en el namespace std.
También antes, teníamos funciones dispersas por todos lados pero ahora cada módulo es una clase con métodos relacionados, además el manejo de memoria es más automática.

### ✍️ Descripción de las clases creadas
- las clases nuevas funcionan como las struct/funciones anteriormente usadas en la version del codigo en C
- **Calculator:** Se encarga de las operaciones matemáticas básicas. Tiene métodos para suma, resta, multiplicación, división, potencias y raíces cuadradas.

- **Functions:** Parte principal del programa ya que Contiene todas las funciones matemáticas que podemos usar: seno, coseno, exponencial, logaritmo, y polinomios

- **Calculus:** Se especializa en cálculo avanzado. Calcula límites aproximando por ambos lados, derivadas usando métodos numéricos precisos, e integrales con la regla de Simpson.

- **Equations:** Resuelve problemas de búsqueda de raíces. Ofrece dos métodos: bisección para cuando sabemos que hay una raíz en un intervalo, y Newton

- **Vector y Matrix:** Manejan el álgebra lineal. Matrix puede sumar y multiplicar matrices, calcular determinantes, inversas y resolver sistemas de ecuaciones y Vector trabaja con Matrix para representar soluciones.

- **Plot:** Genera gráficos en la terminal usando caracteres. Toma una función matemática y un rango, y crea una representación visual con ejes coordenados y la curva de la función.

### 📤 Ejemplo de ejecucuión
![ejemplo de ejecución](https://github.com/ecaroca/Code-Quartet/blob/main/ejecucion_hito2.webp)
  
### 💥 Dificultades encontradas
- El cambio del uso de struct a clases dio problemas en su implementación.


### 🚨 Intrucciones de ejecución
-El compilador usado es "g++ std=gnu++17", para poder compilar el programa con normalidad se debe compilar con la carpeta suite_matematica_c

# 📍Hito 3: Interfaz gráfica
- **Objetivo:** El objetivo de la creación esta interfaz es permitir que la utilización de nuestro programa sea más simple e intuitiva para el usuario, sin necesidad de tener concimientos previos de programación y/o uso de consola para acceder al código.

## 📊 Elementos Principales
-
-
-
-
## 🗳️ Comportamiento Esperado
-
## 💡 Ejemplos de Ejecución
- [Foto aquí]

## 🔎 Uso de Signals y Slots
-
-

## 🚨 Principales Desafíos Durante este Hito 3
- En comparación con los Hitos anteriores, durante esta etapa del proyecto tuvimos mayores complicaciones, ya que de por sí, nos costaba más esta tema de QT y cómo lo implementaríamos en nuestro programa; el tiempo se nos redució con otros deberes académicos y la organización de nuestros roles se vió afectada por el retiro de un compañero. Si bien, la mayoría de estas razones no cuentan como justificación alguna, sí influyeron en nuestro desempeño final.
