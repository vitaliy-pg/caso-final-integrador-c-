#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
struct ColorConsole
{
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};
struct ConsoleBox
{
    void new_text() {/*...*/}
    void set_text(const string &text) { cout << text << endl; }
};

ConsoleBox *consoleBox = new ConsoleBox;
void load_script(const char* filename, bool show_script = false)
{
    string script;
    FILE* f = nullptr;

    try
    {
        // Intentar abrir el archivo en modo lectura binaria
        f = fopen(filename, "rb");
        if (!f)
        {
            cerr << "Error de apertura de " << filename << endl;
            return;
        }
        int c;
        char buf[4001];
        while ((c = fread(buf, 1, 4000, f)) > 0)
        {
            buf[c] = 0;
            script.append(buf);
        }
        fclose(f);
        f = nullptr;

        if (show_script)
        {

            cout << ColorConsole::fg_blue << ColorConsole::bg_white;
            cout << script << endl;
        }
        consoleBox->new_text(); // <--- Aquí se llama a la función new_text
        consoleBox->set_text(script);   // <--- Aquí se llama a la función set_text
    }

    catch (...)
    {
        // Capturar cualquier excepción durante la lectura del archivo
        cerr << "Error durante la lectura del archivo" << endl;
        // Cerrar el archivo si aún está abierto después de un error
        if(f)
            fclose(f);
    }
}

void load_script()
{
    char filename[500];
    printf("Archivo: ");


    scanf("%499s", filename);
    load_script(filename, true);
}