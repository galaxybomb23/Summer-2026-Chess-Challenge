
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
    DEBUG &&std::cout << "Test statement";
    Board board(8, 8);
    board.initGame();
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

        // print point eval
        if (command == ":point" || command == ":p")
        {
            auto points = board.pointEval();
            message = "Points on the Board: " +
                      std::to_string(points) + " \n" + (points > 0 ? "White is Winning" : points < 0 ? "Black Is Winning"
                                                                                                     : "Its all tied Up");

            continue;
        }

        // legal moves command
        if (command == ":list moves" || command == ":lm")
        {
            std::cout << "Legal moves:\n";
            for (auto move : board.legalMoves())
            {
                std::cout << move << "\n";
            }
        }

        // import FEN command

        // Export FEN command

        //

        message = "Unknown command: " + command;
    }

    return 0;
}
