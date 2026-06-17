#include "../../include/productos/SofaVictoriano.hpp"
#include <iostream>

bool SofaVictoriano::tienePatas() const 
    {
        std::cout << "🛋️ [Sofá Victoriano] -> Verificación estructural: Posee patas robustas de nogal barnizado.\n";
        return true;
    }

void SofaVictoriano::recostarse() const 
    {
        std::cout << "🛋️ [Sofá Victoriano] -> Acción: Te recostás en un respaldo alto con tapizado capitoné.\n";
    }