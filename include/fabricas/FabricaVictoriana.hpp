#pragma once
#include "FabricaMuebles.hpp"

// Implementación concreta de la fábrica para la familia de estilo "Victoriano".
class FabricaVictoriana : public FabricaMuebles 
    {
        public:
            ~FabricaVictoriana() override = default;

            [[nodiscard]] Silla* crearSilla() const override;
            [[nodiscard]] Sofa* crearSofa() const override;
            [[nodiscard]] Mesita* crearMesita() const override;
    };