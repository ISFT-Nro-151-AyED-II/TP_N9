#pragma once
#include "Sofa.hpp"

// Variante concreta del producto Sofa.
class SofaModerno : public Sofa 
    {
        public:
            ~SofaModerno() override = default;

            [[nodiscard]] bool tienePatas() const override;
            
            void recostarse() const override;
    };