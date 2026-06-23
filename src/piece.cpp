
#include "piece.hpp"

Piece::Piece(int row, int col, Color color, PieceType type)
    : row(row), col(col), hasMoved(false), color(color), type(type)
{
}

int Piece::value()
{
    int val;
    switch (type)

    {
    case PieceType::KING:
        val = 10; // doesn't matter bc both sides will balance to 0
        break;
    case PieceType::BISHOP:

    case PieceType::KNIGHT:
        val = 3;
        break;
    case PieceType::ROOK:
        val = 5;
        break;

    case PieceType::PAWN:
        val = 1;
        break;
    case PieceType::QUEEN:
        val = 9;
        break;
    }

    return color == Color::WHITE ? val : -val;
}
