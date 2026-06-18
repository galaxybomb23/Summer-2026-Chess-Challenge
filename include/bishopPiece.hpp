#ifndef BISHOPPIECE_HPP
#define BISHOPPIECE_HPP

#include "piece.hpp"

class BishopPiece : public Piece
{
public:
    BishopPiece(int row, int col, Color color);

    bool isValidMove(const Move &move, const Board &board) const override;
    std::vector<Move> getPossibleMoves(const Board &board) const override;
    std::string toString() const override;
};

#endif
