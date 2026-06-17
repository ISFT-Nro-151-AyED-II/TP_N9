#pragma once
#include "Sofa.hpp"

// Variante concreta del producto Sofa.
class SofaVictoriano : public Sofa 
    {
        public:
            ~SofaVictoriano() override = default;

            [[nodiscard]] bool tienePatas() const override;
            
            void recostarse() const override;
    };