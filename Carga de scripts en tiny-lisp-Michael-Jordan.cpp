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