#pragma once
#include "Silla.hpp"

// Variante concreta del producto Silla.
class SillaModerna : public Silla 
    {
        public:
            ~SillaModerna() override = default;

            // Se mantiene el [[nodiscard]] por consistencia con la interfaz, asegurando que el estado booleano 
            // no sea ignorado por el cliente.
            [[nodiscard]] bool tienePatas() const override;
            
            void sentarse() const override;
    };