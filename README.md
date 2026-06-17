# 💻 Trabajo Práctico N°9: Unidad N°3 - Primera Parte

**Instituto Superior de Formación Técnica Nº 151**   
**Carrera:** Tecnicatura Superior en Análisis de Sistemas  
**Materia:** Algoritmos y Estructuras de Datos II  
**Tema:** Patrones de Diseño Creacionales - Abstract Factory  
**Alumno:** David Hernán Bravo  

---

## 💡 Enfoque Técnico y Arquitectura

### 📂 Estructura del Proyecto

```text
📦 TP_N9
 ┃
 ┣ 📜 main.cpp              # 🚀 Punto de entrada principal y ejecución del cliente polimórfico.
 ┣ 📜 compilar.bat          # 🛠️ Script de automatización de compilación rigurosa en Windows (GCC/CMD).
 ┣ 📜 README.md             # 📖 Documentación técnica, enfoque de arquitectura y simulación de consola.
 ┃
 ┣ 📂 diagramas             # 📊 Modelado estricto bajo el estándar UML 2.5.
 ┃ ┣ 📜 DiagramaClases.uml   # 📐 Código Mermaid detallando la jerarquía y relaciones de clases.
 ┃ ┗ 📜 DiagramaSecuencia.uml# ⏱️ Código Mermaid ilustrando el ciclo de vida de los objetos en el Heap.
 ┃
 ┣ 📂 include               # 📋 Contratos e interfaces puras del sistema (Headers).
 ┃ ┣ 📂 fabricas            # 🏭 Abstracciones creacionales.
 ┃ ┃ ┣ 📜 FabricaMuebles.hpp# 🌟 Interfaz de la Fábrica Abstracta (Abstract Factory)
 ┃ ┃ ┣ 📜 FabricaModerna.hpp# 🔹 Declaración de la fábrica concreta de estilo Moderno.
 ┃ ┃ ┗ 📜 FabricaVictoriana.hpp # 🔸 Declaración de la fábrica concreta de estilo Victoriano.
 ┃ ┃
 ┃ ┗ 📂 productos           # 🪑 Abstracciones de los productos de la mueblería.
 ┃   ┣ 📜 Silla.hpp         # 🌟 Interfaz pura para el tipo de producto Silla.
 ┃   ┣ 📜 SillaModerna.hpp  # 🔹 Declaración de la variante Silla Moderna.
 ┃   ┣ 📜 SillaVictoriana.hpp# 🔸 Declaración de la variante Silla Victoriana.
 ┃   ┣ 📜 Sofa.hpp          # 🌟 Interfaz pura para el tipo de producto Sofá.
 ┃   ┣ 📜 SofaModerno.hpp   # 🔹 Declaración de la variante Sofá Moderno.
 ┃   ┣ 📜 SofaVictoriano.hpp# 🔸 Declaración de la variante Sofá Victoriano.
 ┃   ┣ 📜 Mesita.hpp        # 🌟 Interfaz pura para el tipo de producto Mesita.
 ┃   ┣ 📜 MesitaModerna.hpp # 🔹 Declaración de la variante Mesita Moderna.
 ┃   ┗ 📜 MesitaVictoriana.hpp# 🔸 Declaración de la variante Mesita Victoriana.
 ┃
 ┗ 📂 src                   # 🛠️ Código fuente e implementación de la lógica de negocio (.cpp).
   ┣ 📂 fabricas            # 🏗️ Lógica de instanciación en el Heap.
   ┃ ┣ 📜 FabricaModerna.cpp# 🔹 Implementación de la creación de la familia Moderna.
   ┃ ┗ 📜 FabricaVictoriana.cpp # 🔸 Implementación de la creación de la familia Victoriana.
   ┃
   ┗ 📂 productos           # 🎬 Comportamientos específicos de cada mueble.
     ┣ 📜 SillaModerna.cpp  # 🔹 Lógica y trazas visuales de la Silla Moderna.
     ┣ 📜 SillaVictoriana.cpp# 🔸 Lógica y trazas visuales de la Silla Victoriana.
     ┣ 📜 SofaModerno.cpp   # 🔹 Lógica y trazas visuales del Sofá Moderno.
     ┣ 📜 SofaVictoriano.cpp# 🔸 Lógica y trazas visuales del Sofá Victoriano.
     ┣ 📜 MesitaModerna.cpp # 🔹 Lógica y trazas visuales de la Mesita Moderna.
     ┗ 📜 MesitaVictoriana.cpp# 🔸 Lógica y trazas visuales de la Mesita Victoriana.
```


Para la resolución de este simulador de mueblería, se aplicó un diseño orientado a objetos estricto y modularizado, garantizando un bajo acoplamiento y alta cohesión. A continuación, el racional técnico detrás de las decisiones de implementación:

### 1. Gestión de Memoria y Ownership
En C++, la memoria no se limpia sola. Las fábricas concretas (`FabricaModerna`, `FabricaVictoriana`) operan asignando memoria dinámicamente en el Heap mediante el operador `new` y retornando punteros crudos (`Silla*`, `Sofa*`, `Mesita*`).
* **Decisión:** Se transfirió explícitamente el *ownership* (propiedad) al código cliente (`main.cpp`). Es responsabilidad indelegable de la función que consume la fábrica ejecutar el `delete` polimórfico de cada objeto para evitar *memory leaks*.
* **Seguridad:** Todas las interfaces base definen un destructor virtual (`virtual ~Clase() = default;`). Sin esto, destruir una instancia derivada a través de un puntero de la clase base resultaría en un comportamiento indefinido.

### 2. Eficiencia de Compilación y Forward Declarations
En la interfaz `FabricaMuebles.hpp` no se incluyeron las cabeceras de los productos (`#include "Silla.hpp"`, etc.). En su lugar, se utilizaron declaraciones adelantadas (`class Silla;`).
* **Justificación:** Al trabajar únicamente con punteros como valor de retorno, el compilador no necesita conocer el tamaño exacto del objeto en memoria durante el chequeo de esta cabecera. Esto reduce la carga del preprocesador y optimiza drásticamente los tiempos de compilación en sistemas escalables.

### 3. Principios SOLID Aplicados
* **Open/Closed Principle (OCP):** El sistema está abierto a la extensión pero cerrado a la modificación. Si mañana necesitamos agregar la familia `MueblesArtDeco`, solo creamos las clases concretas y `FabricaArtDeco`, sin alterar una sola línea del código cliente existente ni de las fábricas actuales.
* **Single Responsibility Principle (SRP):** Las clases de productos solo definen su estado/comportamiento. Las fábricas solo se encargan de instanciarlos.

### 4. Complejidad Algorítmica
* **Tiempo:** $O(1)$. La instanciación de las familias de objetos mediante los métodos `crearSilla()`, `crearSofa()`, etc., es de tiempo constante. No existen bucles ni evaluaciones condicionales complejas; la inyección de dependencias se resuelve directamente en tiempo de ejecución a través de la *vtable* (Virtual Method Table).
* **Espacio:** $O(1)$ adicional por objeto creado. La memoria ocupada corresponde estrictamente al tamaño de la instancia en el Heap más el puntero a su *vtable* correspondiente.

### 5. Atributos de C++ Moderno
Se utilizaron características como `[[nodiscard]]` en las interfaces para forzar al compilador a emitir advertencias si el código cliente ignora el puntero retornado por una fábrica (evitando fugas instantáneas de memoria) o el valor booleano del método `tienePatas()`.

---

## 🖥️ Simulación de Ejecución (Consola)

El sistema fue configurado incluyendo `<windows.h>` e inyectando `SetConsoleOutputCP(CP_UTF8)` para garantizar la compatibilidad de caracteres UTF-8 en CMD/PowerShell.

A continuación, la salida estándar de una ejecución exitosa:

```text
========================================================
   Simulador de Mueblería - Patrón Abstract Factory
========================================================

🛒 Cliente solicita un juego de muebles MODERNOS:

🏭 [Fabrica Moderna] -> 🪑 Instanciando Silla Moderna (Heap allocation).
🏭 [Fabrica Moderna] -> 🛋️ Instanciando Sofá Moderno (Heap allocation).
🏭 [Fabrica Moderna] -> 🪚 Instanciando Mesita Moderna (Heap allocation).

 Ejecutando comportamientos polimórficos
=========================================

🪑 [Silla Moderna] -> Verificación estructural: Posee 4 patas metálicas minimalistas.
🪑 [Silla Moderna] -> Acción: Te sentás en una superficie ergonómica de polímero.
🛋️ [Sofá Moderno] -> Verificación estructural: No posee patas visibles (diseño al nivel del suelo).
🛋️ [Sofá Moderno] -> Acción: Te recostás en un sillón modular de líneas rectas y tela sintética.
🪚 [Mesita Moderna] -> Acción: Apoyás tu taza de café sobre una superficie de vidrio templado.

🧹 [Gestor de Memoria] -> Liberando recursos del Heap (Evitando Memory Leaks)...

--------------------------------------------------------------------------------------

🛒 Cliente solicita un juego de muebles VICTORIANOS:

🏭 [Fabrica Victoriana] -> 🪑 Tallando Silla Victoriana (Heap allocation).
🏭 [Fabrica Victoriana] -> 🛋️ Tapizando Sofá Victoriano (Heap allocation).
🏭 [Fabrica Victoriana] -> 🪚 Ensamblando Mesita Victoriana (Heap allocation).

 Ejecutando comportamientos polimórficos
=========================================

🪑 [Silla Victoriana] -> Verificación estructural: Posee 4 patas de madera tallada (estilo cabriolé).
🪑 [Silla Victoriana] -> Acción: Te sentás sobre un cojín de terciopelo desgastado pero elegante.
🛋️ [Sofá Victoriano] -> Verificación estructural: Posee patas robustas de nogal barnizado.
🛋️ [Sofá Victoriano] -> Acción: Te recostás en un respaldo alto con tapizado capitoné.
🪚 [Mesita Victoriana] -> Acción: Apoyás un candelabro sobre una superficie de caoba maciza.

🧹 [Gestor de Memoria] -> Liberando recursos del Heap (Evitando Memory Leaks)...


✅ Ejecución finalizada correctamente. Memoria limpia.