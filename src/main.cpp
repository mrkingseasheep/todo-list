#include <cstdlib>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>

int main() {
    using namespace ftxui;
    Element document = hbox({
        window(
            text("TODO List"),
            text("Welcome to your new TODO list app! In the modern age of "
                 "hyperactive everything with scrolly bars and infinite feeds "
                 "it's hard to find an app that just does what it says.")) |
            color(Color::Blue),
        text("Tree") | border | color(Color::Blue),
        gaugeDown(0.5) | border | color(Color::Blue),
    });

    auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));

    Render(screen, document);
    screen.Print();

    auto& pixel = screen.PixelAt(9, 9);
    pixel.character = U'A';
    pixel.bold = true;
    pixel.foreground_color = Color::Blue;

    return EXIT_SUCCESS;
}
