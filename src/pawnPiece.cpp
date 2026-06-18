#include "pawnPiece.hpp"

PawnPiece::PawnPiece(int row, int col, Color color)
    : Piece(row, col, color, PieceType::PAWN) {}

bool PawnPiece::isValidMove(const Move &move, const Board &board) const
{
    // TODO: Implement pawn movement validation (1 or 2 squares forward, diagonals for captures)
    return false;
}

std::vector<Move> PawnPiece::getPossibleMoves(const Board &board) const
{
    std::vector<Move> moves;
    // TODO: Populate with legal pseudo-moves
    return moves;
}

std::string PawnPiece::toString() const
{
    return (color == Color::WHITE) ? "♙" : "♟";
}
