#pragma once
#include "Silla.hpp"

// Variante concreta del producto Silla.
class SillaVictoriana : public Silla 
    {
        public:
            ~SillaVictoriana() override = default;

            [[nodiscard]] bool tienePatas() const override;
            
            void sentarse() const override;
    };