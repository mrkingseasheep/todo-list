#include <cstdlib>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>

int main() {
    using namespace ftxui;

    auto screen = Screen::Create(Dimension::Fixed(32), Dimension::Fixed(16));
    Element todo = vbox({text("TODO List:") | bold | color(Color::Blue),
                         gauge(6), text("The end")});

    // docs https://arthursonzogni.github.io/FTXUI/
    // so much documentation

    todo = border(todo);
    Render(screen, todo);
    screen.Print();

    /*text("Welcome to your new TODO app :D");*/
    screen.Print();

    auto& pixel = screen.PixelAt(9, 9);
    pixel.character = U'A';
    pixel.bold = true;
    pixel.foreground_color = Color::Blue;

    return EXIT_SUCCESS;
}
