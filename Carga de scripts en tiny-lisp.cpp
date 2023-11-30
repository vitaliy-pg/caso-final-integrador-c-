#include <iostream>
#include <fstream>
#include <string>

void load_script(const char* filename, bool show_script = false) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        if (show_script) {
            std::cout << "Contenido del archivo '" << filename << "':" << std::endl;
            while (std::getline(file, line)) {
                std::cout << line << std::endl;

            }
        } else {
            // Si show_script es false, indicar que el archivo se cargó en la consola
            std::cout << "Archivo '" << filename << "' cargado en la consola." << std::endl;
        }
        file.close();
    } else {
        // Mostrar un mensaje de error si no se pudo abrir el archivo
        std::cerr << "No se pudo abrir el archivo '" << filename << "'." << std::endl;
    }
}

void load_script() {