#pragma once

// Interfaz pura que define el contrato para cualquier variante de Mesita.
class Mesita 
    {
        public:
            virtual ~Mesita() = default;

            // El const asegura que invocar este método no alterará el estado interno del objeto.
            virtual void apoyarObjetos() const = 0;
    };