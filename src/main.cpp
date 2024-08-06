#include <cstdlib>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>

int main() {
    using namespace ftxui;

    Element doc = hbox({
        text("left") | border,
        text("middle") | border | flex,
        text("right") | border,
    });

    auto screen = Screen::Create(Dimension::Full(), // width
                                 Dimension::Fit(doc));

    Render(screen, doc);
    screen.Print();

    return EXIT_SUCCESS;
}
