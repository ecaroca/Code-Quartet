# ⚙️ Resgistro de IA:
## 📍 Versión de la IA utilizada
- **Modelo**: ChatGPT **GPT-5**  
- **Proveedor**: OpenAI  
- **Fecha de generación**: Septiembre 2025

## 📍 Uso de IA/Prompts
- 🔎 Como grupo se discutió cual sería la mejor manera de cumplir con nuestro objetivo general, y se llegó a la conclusión de que una calculara, la cual le facilite la interacción con el usuario, sería la forma más apropiada para cumplirlo. Se propusieron ideas sobre qué operaciones realizaría, el menú y cómo sería su lógica de implementación, y, con esto mente, se generó un prompt para realizar cada operación de dicha calculadora.
 
- ### Ejemplo de los distintos prompt utilizados:

#### 1. Funciones y definiciones

**`functions.h` / `functions.c`**
*   **¿Qué hace?** Contiene la función `f_eval` que evalúa diferentes funciones matemáticas (sin(x), cos(x), etc.) según un código numérico (`k`).
*   **Prompt:** *"Necesito un archivo que tenga una función `f_eval(k, x)`. Según el valor de `k` (del 1 al 6) debe retornar sin(x), cos(x), exp(x), log(x) (solo si x>0), x², o x³-x-2. Para cualquier otro k, que devuelva NAN(de la librería de math.h)."*

#### 2. Código para calcular operaciones básicas

**`calculator.h` / `calculator.c`**
*   **¿Qué hace?** Operaciones aritméticas simples directamente con números.
*   **Prompt:** *"Necesito un archivo con funciones para sumar, restar, multiplicar, dividir, potenciar y sacar raíz cuadrada. Las funciones deben ser simples, solo reciben dos números (uno para la raíz) y devuelven el resultado."*

#### 3. Código que implementa las funciones de cálculo

**`calculus.h` / `calculus.c`**
*   **¿Qué hace?** Implementa las operaciones fundamentales de cálculo (límites, derivadas, integrales) de forma numérica, usando la función `f_eval` definida antes.
*   **Prompt:** *"Necesito un archivo que calcule límites (acercándose por izquierda y derecha), derivadas (usando la fórmula de diferencia central) e integrales (usando la regla de Simpson). Todas estas operaciones deben funcionar para cualquier función de nuestro catálogo (`f_eval`)."*

#### 4. Código para resolver ecuaciones

**`equations.h` / `equations.c`**
*   **¿Qué hace?** Encuentra raíces (puntos donde f(x)=0) usando los métodos de **isección** y **Newton-Raphson** (fue investigado). También resuelve sistemas de ecuaciones no lineales en 2D.
*   **Prompt:** *"Necesito un archivo para encontrar ceros de funciones. Debe tener dos métodos: 1) Bisección, que parte un intervalo a la mitad hasta encontrar la raíz. 2) Newton, que usa derivadas para converger más rápido. Además, debe poder resolver sistemas de dos ecuaciones no lineales (como un círculo y una exponencial) usando el método de Newton para sistemas."*

#### 5. Álgebra Linear (Matrices y Vectores)

**`matrix.h` / `matrix.c`**
*   **¿Qué hace?** Define estructuras de datos para matrices y vectores, y todas las operaciones asociadas: suma, multiplicación, determinante, inversa y resolución de sistemas de ecuaciones lineales.
*   **Prompt:** *"Necesito un archivo que defina tipos de datos para matrices y vectores. Tiene que poder crearlos, liberarlos, leerlos del teclado, imprimirlos, sumarlos, multiplicarlos, calcular determinantes e inversas, y resolver sistemas de ecuaciones lineales (Ax = b) usando eliminación gaussiana con los pivotes."*

#### 6. Código para representar visualmente las funciones

**`plot.h` / `plot.c`**
*   **¿Qué hace?** Genera una representación visual de las funciones en la terminal usando arte ASCII.
*   **Prompt:** *"Necesito una función que dibuje el gráfico de una función en la consola. Debe recibir el rango de valores en X y el tamaño del dibujo. Tiene que calcular los valores de Y, encontrar los ejes y dibujar la función con asteriscos `*`."*

### 7. Función main.c

**`main.c`**
*   **¿Qué hace?** Es la interfaz de usuario. Une todos los módulos anteriores en un menú interactivo por consola.
*   **Prompt:** *"Necesito un programa principal con un menú que permita al usuario elegir entre todas las operaciones de la suite. Debe tener submenús para la calculadora, matrices, cálculo, ecuaciones, sistemas y gráficos. Tiene que leer las opciones del usuario, llamar a las funciones correctas de los otros módulos y mostrar los resultados de forma amigable."*
