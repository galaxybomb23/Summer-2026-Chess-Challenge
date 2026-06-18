#ifndef NULLPIECE_HPP
#define NULLPIECE_HPP

#include "piece.hpp"

class NullPiece : public Piece
{
public:
    NullPiece(int row, int col);

    bool isValidMove(const Move &move, const Board &board) const override;
    std::vector<Move> getPossibleMoves(const Board &board) const override;
    std::string toString() const override;
};

#endif
