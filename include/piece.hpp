#ifndef PIECE_HPP
#define PIECE_HPP

#include "common.hpp"

class Piece
{
public:
    // basic piece constructor
    Piece(int row, int col, Color color, PieceType type);
    virtual ~Piece() = default;

    int row;
    int col;
    bool hasMoved;
    Color color;
    PieceType type;

    virtual bool isValidMove(const Move &move, const Board &board) const = 0;
    virtual std::vector<Move> getPossibleMoves(const Board &board) const = 0;
    virtual std::string toString() const = 0;
    int value();
};

#endif
