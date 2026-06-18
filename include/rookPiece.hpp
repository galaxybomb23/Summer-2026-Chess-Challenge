#ifndef ROOKPIECE_HPP
#define ROOKPIECE_HPP

#include "piece.hpp"

class RookPiece : public Piece
{
public:
    RookPiece(int row, int col, Color color);

    bool isValidMove(const Move &move, const Board &board) const override;
    std::vector<Move> getPossibleMoves(const Board &board) const override;
    std::string toString() const override;
};

#endif
