#ifndef PAWNPIECE_HPP
#define PAWNPIECE_HPP

#include "piece.hpp"

class PawnPiece : public Piece
{
public:
    PawnPiece(int row, int col, Color color);

    bool isValidMove(const Move &move, const Board &board) const override;
    std::vector<Move> getPossibleMoves(const Board &board) const override;
    std::string toString() const override;
};

#endif
