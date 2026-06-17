#pragma once

// Forward declarations (Declaraciones adelantadas).
// Evita el #include de los headers de productos, reduciendo el acoplamiento
// y los tiempos de compilación, ya que aquí solo manejamos punteros.
class Silla;
class Sofa;
class Mesita;

// Interfaz creadora (Abstract Factory). 
// Aplica el Principio de Inversión de Dependencias (DIP): el código cliente se acoplará a esta abstracción y 
// no a las implementaciones concretas.
class FabricaMuebles 
    {
        public:
            virtual ~FabricaMuebles() = default;
            // Métodos fábrica. Retornan punteros a las interfaces de los productos.
            // [[nodiscard]] obliga al compilador a emitir un warning si el cliente llama a la función y 
            // no guarda el puntero devuelto, previniendo memory leaks tempranos.
            [[nodiscard]] virtual Silla* crearSilla() const = 0;
            [[nodiscard]] virtual Sofa* crearSofa() const = 0;
            [[nodiscard]] virtual Mesita* crearMesita() const = 0;
    };