#include "../../include/fabricas/FabricaVictoriana.hpp"
#include "../../include/productos/SillaVictoriana.hpp"
#include "../../include/productos/SofaVictoriano.hpp"
#include "../../include/productos/MesitaVictoriana.hpp"
#include <iostream>

Silla* FabricaVictoriana::crearSilla() const 
    {
        std::cout << "🏭 [Fabrica Victoriana] -> 🪑 Tallando Silla Victoriana (Heap allocation).\n";
        // El polimorfismo garantiza que el cliente trate a este objeto solo como 'Silla*'.
        return new SillaVictoriana();
    }

Sofa* FabricaVictoriana::crearSofa() const 
    {
        std::cout << "🏭 [Fabrica Victoriana] -> 🛋️ Tapizando Sofá Victoriano (Heap allocation).\n";
        return new SofaVictoriano();
    }

Mesita* FabricaVictoriana::crearMesita() const 
    {
        std::cout << "🏭 [Fabrica Victoriana] -> 🪚 Ensamblando Mesita Victoriana (Heap allocation).\n";
        return new MesitaVictoriana();
    }