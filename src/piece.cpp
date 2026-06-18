
#include "piece.hpp"

Piece::Piece(int row, int col, Color color, PieceType type)
    : row(row), col(col), hasMoved(false), color(color), type(type)
{
}
