#include "../../include/productos/SillaVictoriana.hpp"
#include <iostream>

bool SillaVictoriana::tienePatas() const 
    {
        std::cout << "🪑 [Silla Victoriana] -> Verificación estructural: Posee 4 patas de madera tallada (estilo cabriolé).\n";
        return true;
    }

void SillaVictoriana::sentarse() const 
    {
        std::cout << "🪑 [Silla Victoriana] -> Acción: Te sentás sobre un cojín de terciopelo desgastado pero elegante.\n";
    }