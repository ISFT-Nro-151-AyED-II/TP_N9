#pragma once
#include "FabricaMuebles.hpp"

// Implementación concreta de la fábrica para la familia de estilo "Moderno".
class FabricaModerna : public FabricaMuebles 
    {
        public:
            ~FabricaModerna() override = default;

            // El override garantiza en tiempo de compilación que estamos respetando estrictamente el contrato 
            // definido en FabricaMuebles.
            [[nodiscard]] Silla* crearSilla() const override;
            [[nodiscard]] Sofa* crearSofa() const override;
            [[nodiscard]] Mesita* crearMesita() const override;
    };