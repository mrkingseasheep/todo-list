#include "ftxui/component/captured_mouse.hpp" // for ftxui
#include "ftxui/component/component.hpp"      // for Input, Renderer, Vertical
#include "ftxui/component/component_base.hpp" // for ComponentBase
#include "ftxui/component/component_options.hpp" // for InputOption
#include "ftxui/component/screen_interactive.hpp" // for Component, ScreenInteractive
#include "ftxui/dom/elements.hpp" // for text, hbox, separator, Element, operator|, vbox, border
#include "ftxui/util/ref.hpp" // for Ref
#include <cstdlib>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/screen.hpp>
#include <vector>

int main() {
    using namespace ftxui;

    std::string fName;
    std::string lName;

    std::vector<std::string> tabName = {
        "Basic Info",
        "TODO List",
        "Settings",
    };
    int selectedTab = 0;
    auto tabToggler = Toggle(&tabName, &selectedTab);

    Component fNameIn = Input(&fName, "First Name:");
    Component lNameIn = Input(&lName, "Last Name");

    auto infoFetch = Container::Vertical({
        fNameIn,
        lNameIn,
    });

    auto renderer = Renderer(infoFetch, [&] {
        return vbox({
                   paragraph(
                       "Welcome to TODO-TREE (please make a better name, come "
                       "on man...). This app is supposed to be simple and "
                       "intuitive to use.") |
                       border | flex,
                   tabToggler->Render(),
                   hbox(text("First Name: "), fNameIn->Render()),
                   hbox(text("Last Name: "), lNameIn->Render()),
                   separator(),
                   text("Your first name: " + fName + " " + lName),
               }) |
               border;
    });

    auto screen = ScreenInteractive::TerminalOutput();
    screen.Loop(renderer);

    return EXIT_SUCCESS;
}
