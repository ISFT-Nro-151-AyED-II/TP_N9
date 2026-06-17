#pragma once

// Interfaz pura que define el contrato para cualquier variante de Silla.
// Los métodos son virtuales puros (= 0) para obligar a las clases derivadas a implementarlos.
class Silla 
    {
        public:
            // Destructor virtual por defecto: Crítico para que el 'delete' desde un puntero base ejecute 
            //correctamente el destructor de la clase derivada.
            virtual ~Silla() = default;

            // Se utiliza 'const' porque consultar si tiene patas o la acción de sentarse no deberían mutar el 
            // estado interno del objeto en memoria.
            // [[nodiscard]] advierte si se llama al método y se ignora su resultado.
            [[nodiscard]] virtual bool tienePatas() const = 0;

            // Método de acción puro.
            virtual void sentarse() const = 0;
    };