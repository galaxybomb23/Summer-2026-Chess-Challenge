#include "bishopPiece.hpp"

BishopPiece::BishopPiece(int row, int col, Color color)
    : Piece(row, col, color, PieceType::BISHOP) {}

bool BishopPiece::isValidMove(const Move &move, const Board &board) const
{
    // TODO: Implement diagonal vector validation
    return false;
}

std::vector<Move> BishopPiece::getPossibleMoves(const Board &board) const
{
    std::vector<Move> moves;
    // TODO: Populate with 4-directional diagonal paths
    return moves;
}

std::string BishopPiece::toString() const
{
    return (color == Color::WHITE) ? "♗" : "♝";
}
