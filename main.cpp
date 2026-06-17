#include <iostream>
#include <windows.h> // Requerido para SetConsoleOutputCP y SetConsoleCP.

// Inclusión exclusiva de interfaces y fábricas concretas.
// El cliente NO conoce ni incluye SillaModerna.hpp, SofaVictoriano.hpp, etc.
// Esto garantiza el desacoplamiento total dictado por el Abstract Factory.
#include "include/fabricas/FabricaMuebles.hpp"
#include "include/fabricas/FabricaModerna.hpp"
#include "include/fabricas/FabricaVictoriana.hpp"
#include "include/productos/Silla.hpp"
#include "include/productos/Sofa.hpp"
#include "include/productos/Mesita.hpp"

// Función cliente que opera PURAMENTE con abstracciones.
// Recibe la interfaz de la fábrica por referencia para aprovechar el polimorfismo.
void probarMuebleria(const FabricaMuebles& fabrica) 
    {
        // 1. La fábrica crea los objetos en el Heap.
        Silla* miSilla = fabrica.crearSilla();
        Sofa* miSofa = fabrica.crearSofa();
        Mesita* miMesita = fabrica.crearMesita();

        std::cout << "\n Ejecutando comportamientos polimórficos\n";
        std::cout << "=========================================\n\n";
        
        // 2. Uso de los productos sin saber sus clases concretas.
        miSilla->tienePatas();
        miSilla->sentarse();

        miSofa->tienePatas();
        miSofa->recostarse();

        miMesita->apoyarObjetos();

        // 3. RESPONSABILIDAD CRÍTICA: Liberación de memoria.
        // Al usar punteros crudos devueltos por la fábrica, el ownership recae acá.
        std::cout << "\n🧹 [Gestor de Memoria] -> Liberando recursos del Heap (Evitando Memory Leaks)...\n";
        delete miSilla;
        delete miSofa;
        delete miMesita;
    }

int main() 
    {
        // Configuración estricta para CMD/PowerShell en Windows.
        // Fuerza la codificación UTF-8 para renderizar correctamente tildes, eñes y emojis.
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);

        std::cout << "\n========================================================\n";
        std::cout << "   Simulador de Mueblería - Patrón Abstract Factory\n";
        std::cout << "========================================================\n\n";

        std::cout << "🛒 Cliente solicita un juego de muebles MODERNOS:\n\n";
        // Instanciación en Stack de la fábrica (se destruye sola al salir del scope)
        FabricaModerna fabricaModerna;
        probarMuebleria(fabricaModerna);

        std::cout << "\n--------------------------------------------------------------------------------------\n\n";

        std::cout << "🛒 Cliente solicita un juego de muebles VICTORIANOS:\n\n";
        // Siguiendo el Diagrama de Secuencia: instanciación dinámica de la fábrica en el Heap
        FabricaMuebles* fabricaVictoriana = new FabricaVictoriana();
        probarMuebleria(*fabricaVictoriana);
        
        // Limpieza de la fábrica dinámica
        delete fabricaVictoriana;

        std::cout << "\n\n✅ Ejecución finalizada correctamente. Memoria limpia.\n";
        return 0;
    }