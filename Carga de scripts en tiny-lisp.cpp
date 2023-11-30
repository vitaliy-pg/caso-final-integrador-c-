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