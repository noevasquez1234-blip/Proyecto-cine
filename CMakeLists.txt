cmake_minimum_required(VERSION 3.17)
project(untitled CXX)

set(CMAKE_CXX_STANDARD 17)

# Solo necesitamos la ruta de los headers (.h) para que reconozca la estructura MYSQL*
include_directories("C:/Program Files/MySQL/MySQL Server 26.10/include")

# Indicar a CMake dónde buscar los archivos de cabecera de tu proyecto
include_directories("Sis_cine_entrega_final_proyecto_de_unidad")

add_executable(untitled
        Sis_cine_entrega_final_proyecto_de_unidad/main.cpp
        Sis_cine_entrega_final_proyecto_de_unidad/Validaciones.cpp
        Sis_cine_entrega_final_proyecto_de_unidad/Precios.cpp
        Sis_cine_entrega_final_proyecto_de_unidad/Modelos_de_sala.cpp
        Sis_cine_entrega_final_proyecto_de_unidad/Vista_mapa.cpp
        Sis_cine_entrega_final_proyecto_de_unidad/Reporte_finan.cpp
        Sis_cine_entrega_final_proyecto_de_unidad/controlador_cliente.cpp
        Sis_cine_entrega_final_proyecto_de_unidad/Controlador_admin.cpp
        Sis_cine_entrega_final_proyecto_de_unidad/coneccion_Bd.cpp
)

# Enlazamos únicamente las librerías estándar de sockets de Windows
target_link_libraries(untitled ws2_32)