#include "rookPiece.hpp"

RookPiece::RookPiece(int row, int col, Color color)
    : Piece(row, col, color, PieceType::ROOK) {}

bool RookPiece::isValidMove(const Move &move, const Board &board) const
{
    // TODO: Implement straight-line file/rank validation
    return false;
}

std::vector<Move> RookPiece::getPossibleMoves(const Board &board) const
{
    std::vector<Move> moves;
    // TODO: Populate with horizontal and vertical moves
    return moves;
}

std::string RookPiece::toString() const
{
    return (color == Color::WHITE) ? "♖" : "♜";
}
