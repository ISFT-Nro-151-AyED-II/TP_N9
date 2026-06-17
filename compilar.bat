@echo off
:: Forzamos la consola a usar UTF-8 para leer bien los acentos
chcp 65001 > nul

echo [INFO] Iniciando compilacion rigurosa en C++17...
echo [INFO] Directorio raiz: %CD%

:: Compilamos todos los .cpp de las subcarpetas. 
:: Usamos -I include para decirle al compilador donde buscar los .hpp
g++ -std=c++17 -Wall -Wextra -I include main.cpp src/productos/*.cpp src/fabricas/*.cpp -o TP9_Patrones.exe

:: Verificamos si hubo errores de compilacion
if %errorlevel% neq 0 (
    echo.
    echo [ERROR CRITICO] La compilacion fallo. Revisa el log de arriba para corregir la sintaxis.
    exit /b %errorlevel%
)

echo [EXITO] Compilacion finalizada sin errores.
echo ==========================================================
echo [INFO] Ejecutando TP9_Patrones.exe...
echo ==========================================================
echo.

:: Ejecutamos el programa resultante
TP9_Patrones.exe

echo.
echo ==========================================================
echo [INFO] Fin de la ejecucion.
pause