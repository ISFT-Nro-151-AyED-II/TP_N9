#pragma once

// Interfaz pura que define el contrato para cualquier variante de Sofa.
class Sofa
    {
        public:
            virtual ~Sofa() = default;

            [[nodiscard]] virtual bool tienePatas() const = 0;
            
            virtual void recostarse() const = 0;
    };