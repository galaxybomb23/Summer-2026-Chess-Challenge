#ifndef KINGPIECE_HPP
#define KINGPIECE_HPP

#include "piece.hpp"

class KingPiece : public Piece
{
public:
    // Fixed the missing Color argument from the baseline code archetype
    KingPiece(int row, int col, Color color);

    bool isValidMove(const Move &move, const Board &board) const override;
    std::vector<Move> getPossibleMoves(const Board &board) const override;
    std::string toString() const override;
};

#endif
