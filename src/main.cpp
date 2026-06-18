
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>

#include "board.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace
{
    ftxui::Element board_to_element(const Board &board)
    {
        std::istringstream input(board.toString());
        std::string line;
        std::vector<ftxui::Element> lines;

        while (std::getline(input, line))
        {
            lines.push_back(ftxui::text(line));
        }

        return ftxui::vbox(std::move(lines));
    }

    void render_screen(const Board &board, const std::string &message)
    {
        using namespace ftxui;

        auto document = vbox({
                            text("Summer Chess Challenge") | bold | center,
                            separator(),
                            text(message),
                            separator(),
                            board_to_element(board),
                        }) |
                        border;

        auto screen = Screen::Create(Dimension::Fit(document));
        Render(screen, document);

        std::cout << screen.ToString() << '\n';
    }
} // namespace

int main()
{
    Board board(8, 8);
    std::string command;
    std::string message = "Commands: :help, :board, :quit";

    std::cout << "Welcome to the Chess Challenge!\n";

    while (true)
    {
        render_screen(board, message);
        std::cout << "> ";

        if (!std::getline(std::cin, command))
        {
            break;
        }

        // quit/exit command
        if (command == ":quit" || command == ":q")
        {
            break;
        }

        // help command
        if (command == ":help" || command == ":h")
        {
            message = "Commands: :help, :board, :quit";
            continue;
        }

        // legal moves command

        // import FEN command

        // Export FEN command

        //

        message = "Unknown command: " + command;
    }

    return 0;
}
