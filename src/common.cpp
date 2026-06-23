
#include "common.hpp"
// #include <string>

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
