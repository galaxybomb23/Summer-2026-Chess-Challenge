
#ifndef COMMON_HPP
#define COMMON_HPP

#include <ostream>
#include <string>
#include <vector>

#define DEBUG true

enum Color
{
    BLACK = 0,
    WHITE = 1
};

enum MoveType
{
    NORMAL,
    CASTLING,
    EN_PASSANT,
    PROMOTION
};

enum PieceType
{
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING,
    NONE
};

class Piece;
class Board;

struct Move
{
    int fromX = 0;
    int fromY = 0;
    int toX = 0;
    int toY = 0;
    Piece *pieceMoved = nullptr;
    Piece *pieceCaptured = nullptr;
    int moveNumber = 0;
    MoveType moveType = NORMAL;
};

std::string PieceTypeToString(PieceType piece)
{
    std::string ret;

    switch (piece)
    {
    case PieceType::KING:
        ret = "KING";
        break;
    case PieceType::BISHOP:
        ret = "BISHOP";
        break;
    case PieceType::ROOK:
        ret = "ROOK";
        break;
    case PieceType::KNIGHT:
        ret = "KNIGHT";
        break;
    case PieceType::PAWN:
        ret = "PAWN";
        break;
    case PieceType::QUEEN:
        ret = "QUEEN";
        break;
    default:
        ret = "UNKNOWN" + piece;
        break;
    }
    return ret;
}

#endif
