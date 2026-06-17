#pragma once
#include "Mesita.hpp"

// Variante concreta del producto Mesita.
class MesitaVictoriana : public Mesita 
    {
        public:
            ~MesitaVictoriana() override = default;

            void apoyarObjetos() const override;
    };