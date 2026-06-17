#include "../../include/fabricas/FabricaModerna.hpp"
#include "../../include/productos/SillaModerna.hpp"
#include "../../include/productos/SofaModerno.hpp"
#include "../../include/productos/MesitaModerna.hpp"
#include <iostream>

// El uso de std::cout en una fábrica creacional permite trazar la inyección de dependencias.
// En un entorno productivo, esto se delegaría a un componente de Logging.

Silla* FabricaModerna::crearSilla() const 
    {
        std::cout << "🏭 [Fabrica Moderna] -> 🪑 Instanciando Silla Moderna (Heap allocation).\n";
        // El cliente asume la propiedad (ownership) del puntero devuelto.
        return new SillaModerna();
    }

Sofa* FabricaModerna::crearSofa() const 
    {
        std::cout << "🏭 [Fabrica Moderna] -> 🛋️ Instanciando Sofá Moderno (Heap allocation).\n";
        return new SofaModerno();
    }

Mesita* FabricaModerna::crearMesita() const 
    {
        std::cout << "🏭 [Fabrica Moderna] -> 🪚 Instanciando Mesita Moderna (Heap allocation).\n";
        return new MesitaModerna();
    }