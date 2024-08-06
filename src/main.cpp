#include <cstdlib>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>

int main() {
    using namespace ftxui;

    /*Element doc = hbox({*/
    /*    text("TODO") | border,*/
    /*    text("Tree") | border | flex,*/
    /*});*/

    /*auto screen = Screen::Create(Dimension::Full(), // width*/
    /*                             Dimension::Fit(doc));*/

    /*Render(screen, doc);*/
    /*screen.Print();*/

    auto screen = Screen::Create(Dimension::Fixed(32), Dimension::Fixed(16));
    auto& pixel = screen.PixelAt(9, 9);
    pixel.character = U'A';
    pixel.bold = true;
    pixel.foreground_color = Color::Blue;

    std::cout << screen.ToString() << std::endl;

    return EXIT_SUCCESS;
}
