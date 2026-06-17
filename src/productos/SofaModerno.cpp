#include "../../include/productos/SofaModerno.hpp"
#include <iostream>

bool SofaModerno::tienePatas() const 
    {
        // Decisión de diseño de negocio: el modelo moderno minimalista va al ras del piso.
        std::cout << "🛋️ [Sofá Moderno] -> Verificación estructural: No posee patas visibles (diseño al nivel del suelo).\n";
        return false;
    }

void SofaModerno::recostarse() const 
    {
        std::cout << "🛋️ [Sofá Moderno] -> Acción: Te recostás en un sillón modular de líneas rectas y tela sintética.\n";
    }