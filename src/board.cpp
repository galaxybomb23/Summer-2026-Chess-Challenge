#include "board.hpp"
#include "nullPiece.hpp"
#include "kingPiece.hpp"

#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>

Board::Board(int rows, int cols)
    : board(rows, std::vector<Piece *>(cols, nullptr)),
      isWhiteTurn(true),
      canWhiteCastleKingside(true),
      canWhiteCastleQueenside(true),
      canBlackCastleKingside(true),
      canBlackCastleQueenside(true),
      turnNumber(1),
      numRows(rows),
      numCols(cols)
{
    reset();
}

Board::~Board()
{
    for (auto &row : board)
    {
        for (auto *&piece : row)
        {
            delete piece;
            piece = nullptr;
        }
    }
}

void Board::reset()
{
    for (auto &row : board)
    {
        for (auto *&piece : row)
        {
            delete piece;
            piece = nullptr;
        }
    }

    for (int row = 0; row < numRows; ++row)
    {
        for (int col = 0; col < numCols; ++col)
        {
            // board[row][col] = new NullPiece(row, col);
            board[row][col] = new KingPiece(row, col, (row < 2) ? Color::WHITE : Color::BLACK);
        }
    }
}

std::string Board::toString() const
{
    std::ostringstream output;

    output << "   a b c d e f g h\n";
    for (int row = 0; row < numRows; row++)
    {
        output << (numRows - row) << " ";
        for (int col = 0; col < numCols; col++)
        {
            if (board[row][col])
            {
                output << board[row][col]->toString();
            }
            else
            {
                output << ".";
            }
        }
        output << '\n';
    }
    output << "   a b c d e f g h\n";
    output << "Turn: " << (isWhiteTurn ? "White" : "Black") << " | Move: " << turnNumber << '\n';
    return output.str();
}

bool Board::isValidMove(const Move &move) const
{
    (void)move;
    return false;
}

void Board::undoMove()
{
    if (!moveHistory.empty())
    {
        moveHistory.pop_back();
    }
}

void Board::placePiece(Color color, PieceType piece, int xcord, int ycord)
{
    (void)color;
    (void)piece;

    if (xcord < 0 || xcord >= numRows || ycord < 0 || ycord >= numCols)
    {
        return;
    }

    delete board[xcord][ycord];
    board[xcord][ycord] = new NullPiece(xcord, ycord);
}

std::ostream &operator<<(std::ostream &os, const Board &board)
{
    os << board.toString();
    return os;
}
