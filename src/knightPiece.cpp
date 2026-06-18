#include "knightPiece.hpp"

KnightPiece::KnightPiece(int row, int col, Color color)
    : Piece(row, col, color, PieceType::KNIGHT) {}

bool KnightPiece::isValidMove(const Move &move, const Board &board) const
{
    // TODO: Implement L-shaped jump validation
    return false;
}

std::vector<Move> KnightPiece::getPossibleMoves(const Board &board) const
{
    std::vector<Move> moves;
    // TODO: Populate with the 8 possible L-shape coordinates
    return moves;
}

std::string KnightPiece::toString() const
{
    return (color == Color::WHITE) ? "♘" : "♞";
}
