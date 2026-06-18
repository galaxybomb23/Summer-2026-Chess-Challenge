#include "nullPiece.hpp"
#include "common.hpp"

NullPiece::NullPiece(int row, int col)
    : Piece(row, col, Color((row + col) % 2), NONE)
{
}

bool NullPiece::isValidMove(const Move &move, const Board &board) const
{
    (void)move;
    (void)board;
    return false;
}

std::vector<Move> NullPiece::getPossibleMoves(const Board &board) const
{
    (void)board;
    return {};
}

std::string NullPiece::toString() const
{
    return color == BLACK ? "⬛" : "⬜";
}
