#include "queenPiece.hpp"

QueenPiece::QueenPiece(int row, int col, Color color)
    : Piece(row, col, color, PieceType::QUEEN) {}

bool QueenPiece::isValidMove(const Move &move, const Board &board) const
{
    // TODO: Implement combined straight-line and diagonal validation
    return false;
}

std::vector<Move> QueenPiece::getPossibleMoves(const Board &board) const
{
    std::vector<Move> moves;
    // TODO: Populate with 8-directional rays
    return moves;
}

std::string QueenPiece::toString() const
{
    return (color == Color::WHITE) ? "♕" : "♛";
}
