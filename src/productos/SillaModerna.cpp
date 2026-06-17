#include "../../include/productos/SillaModerna.hpp"
#include <iostream>

bool SillaModerna::tienePatas() const 
    {
        // Trazabilidad de estado interno sin mutación.
        std::cout << "🪑 [Silla Moderna] -> Verificación estructural: Posee 4 patas metálicas minimalistas.\n";
        return true;
    }

void SillaModerna::sentarse() const 
    {
        std::cout << "🪑 [Silla Moderna] -> Acción: Te sentás en una superficie ergonómica de polímero.\n";
    }