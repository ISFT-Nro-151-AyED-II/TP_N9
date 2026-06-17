#pragma once
#include "Mesita.hpp"

// Variante concreta del producto Mesita.
class MesitaModerna : public Mesita 
    {
        public:
            ~MesitaModerna() override = default;

            void apoyarObjetos() const override;
    };