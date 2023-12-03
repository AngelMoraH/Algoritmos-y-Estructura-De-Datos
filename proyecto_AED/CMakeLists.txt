cmake_minimum_required(VERSION 3.12)
project(PROYECTO_AED)

set(CMAKE_CXX_STANDARD 14)

# Ruta a la carpeta de instalación de SFML
set(SFML_DIR "C:/Users/ANGEL MORA/AED/SFML-2.5.1-windows-vc15-64-bit/SFML/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(PROYECTO_AED main.cpp)
target_link_libraries(PROYECTO_AED sfml-graphics sfml-window sfml-system)
