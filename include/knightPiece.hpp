#ifndef KNIGHTPIECE_HPP
#define KNIGHTPIECE_HPP

#include "piece.hpp"

class KnightPiece : public Piece
{
public:
    KnightPiece(int row, int col, Color color);

    bool isValidMove(const Move &move, const Board &board) const override;
    std::vector<Move> getPossibleMoves(const Board &board) const override;
    std::string toString() const override;
};

#endif
