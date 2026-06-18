#ifndef QUEENPIECE_HPP
#define QUEENPIECE_HPP

#include "piece.hpp"

class QueenPiece : public Piece
{
public:
    QueenPiece(int row, int col, Color color);

    bool isValidMove(const Move &move, const Board &board) const override;
    std::vector<Move> getPossibleMoves(const Board &board) const override;
    std::string toString() const override;
};

#endif
