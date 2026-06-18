#include "kingPiece.hpp"

KingPiece::KingPiece(int row, int col, Color color)
    : Piece(row, col, color, PieceType::KING) {}

bool KingPiece::isValidMove(const Move &move, const Board &board) const
{
    // TODO: Implement basic 1-square movement validation and Castling constraints
    return false;
}

std::vector<Move> KingPiece::getPossibleMoves(const Board &board) const
{
    std::vector<Move> moves;
    // TODO: Scan 8 surrounding squares and check castling flags
    return moves;
}

std::string KingPiece::toString() const
{
    // Renders matching UTF-8 full-width glyphs matching your FTXUI context structure
    return (color == Color::WHITE) ? "♔" : "♚";
}
