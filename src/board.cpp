#include "board.hpp"
#include "nullPiece.hpp"
#include "kingPiece.hpp"
#include "pawnPiece.hpp"
#include "bishopPiece.hpp"
#include "knightPiece.hpp"
#include "rookPiece.hpp"
#include "queenPiece.hpp"

#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>

Board::Board(int rows, int cols)
    : board(rows, std::vector<Piece *>(cols, nullptr)),
      isWhiteTurn(true),
      canWhiteCastleKingside(true),
      canWhiteCastleQueenside(true),
      canBlackCastleKingside(true),
      canBlackCastleQueenside(true),
      turnNumber(1),
      numRows(rows),
      numCols(cols)
{
    reset();
}

Board::~Board()
{
    this->clear();
}

void Board::reset()
{
    // Delete all pieces if any
    this->clear();

    // init all Null pieces
    for (int row = 0; row < numRows; ++row)
    {
        for (int col = 0; col < numCols; ++col)
        {
            board[row][col] = new NullPiece(row, col);
            // board[row][col] = new KingPiece(row, col, (row < 2) ? Color::WHITE : Color::BLACK);
        }
    }
}

void Board::clear()
{
    for (auto &row : board)
    {
        for (auto *&piece : row)
        {
            delete piece;
            piece = nullptr;
        }
    }
}

void Board::initGame()
{
    // verify size is 8x8 or ret
    if (numCols != 8 || numRows != 8)
    {
        DEBUG &&std::cout << "wrong size for function initGame: " << numRows << "x" << numCols << "!= 8x8";
        return;
    }
    // clear board
    this->reset();

    // Black back row:
    this->placePiece(Color::BLACK, PieceType::ROOK, 0, 0);
    this->placePiece(Color::BLACK, PieceType::BISHOP, 0, 1);
    this->placePiece(Color::BLACK, PieceType::KNIGHT, 0, 2);
    this->placePiece(Color::BLACK, PieceType::KING, 0, 3);
    this->placePiece(Color::BLACK, PieceType::QUEEN, 0, 4);
    this->placePiece(Color::BLACK, PieceType::KNIGHT, 0, 5);
    this->placePiece(Color::BLACK, PieceType::BISHOP, 0, 6);
    this->placePiece(Color::BLACK, PieceType::ROOK, 0, 7);

    // Place Black Pawns
    this->placePiece(Color::BLACK, PieceType::PAWN, 1, 0);
    this->placePiece(Color::BLACK, PieceType::PAWN, 1, 1);
    this->placePiece(Color::BLACK, PieceType::PAWN, 1, 2);
    this->placePiece(Color::BLACK, PieceType::PAWN, 1, 3);
    this->placePiece(Color::BLACK, PieceType::PAWN, 1, 4);
    this->placePiece(Color::BLACK, PieceType::PAWN, 1, 5);
    this->placePiece(Color::BLACK, PieceType::PAWN, 1, 6);
    this->placePiece(Color::BLACK, PieceType::PAWN, 1, 7);

    // White Back row:
    this->placePiece(Color::WHITE, PieceType::ROOK, 7, 0);
    this->placePiece(Color::WHITE, PieceType::BISHOP, 7, 1);
    this->placePiece(Color::WHITE, PieceType::KNIGHT, 7, 2);
    this->placePiece(Color::WHITE, PieceType::QUEEN, 7, 3);
    this->placePiece(Color::WHITE, PieceType::KING, 7, 4);
    this->placePiece(Color::WHITE, PieceType::KNIGHT, 7, 5);
    this->placePiece(Color::WHITE, PieceType::BISHOP, 7, 6);
    this->placePiece(Color::WHITE, PieceType::ROOK, 7, 7);

    // Place Black Pawns
    this->placePiece(Color::WHITE, PieceType::PAWN, 6, 0);
    this->placePiece(Color::WHITE, PieceType::PAWN, 6, 1);
    this->placePiece(Color::WHITE, PieceType::PAWN, 6, 2);
    this->placePiece(Color::WHITE, PieceType::PAWN, 6, 3);
    this->placePiece(Color::WHITE, PieceType::PAWN, 6, 4);
    this->placePiece(Color::WHITE, PieceType::PAWN, 6, 5);
    this->placePiece(Color::WHITE, PieceType::PAWN, 6, 6);
    this->placePiece(Color::WHITE, PieceType::PAWN, 6, 7);

    return;
}

bool Board::importFEN(std::string fen)
{
    return false;
}

std::string Board::toString() const
{
    std::ostringstream output;

    output << "   a b c d e f g h\n";
    for (int row = 0; row < numRows; row++)
    {
        output << (numRows - row) << " ";
        for (int col = 0; col < numCols; col++)
        {
            if (board[row][col])
            {
                output << " " << board[row][col]->toString();
            }
            else
            {
                output << ".";
            }
        }
        output << '\n';
    }
    output << "   a b c d e f g h\n";
    output << "Point Eval" output << "Turn: " << (isWhiteTurn ? "White" : "Black") << " | Move: " << turnNumber << '\n';
    return output.str();
}

bool Board::isValidMove(const Move &move) const
{
    // verify move is in bounds of board [0,numRow/Col]
    if (move.toX > numCols || move.toY > numRows || move.toX < 0 || move.toY < 0)
    {
        return false;
    }

    // verify if is valide moveset for piece at starting point
    return board.at(move.fromX).at(move.fromY)->isValidMove(move, *this);
}

void Board::undoMove()
{
    if (!moveHistory.empty())
    {
        moveHistory.pop_back();
    }
}

bool Board::placePiece(Color color, PieceType piece, int xcord, int ycord)
{

    // validate placement is within board
    if (xcord < 0 || xcord >= numRows || ycord < 0 || ycord >= numCols)
    {
        std::cout << "placement out of bounds\n";
        return false;
    }

    // verify new piecetype in ENUM
    if (piece > PieceType::NONE || piece < PieceType::PAWN)
    {
        std::cout << "PieceType out of bounds\n";
        return false;
    }

    // validate old piece *this was a BUG*
    if (board[xcord][ycord] != nullptr)
    {
        DEBUG &&std::cout << "Removing Piece (" << board[xcord][ycord]->toString() << ") from location [" << xcord << "," << ycord << "]\n";
        delete board[xcord][ycord];
    } // if is null ptr, just replace no need to delete

    // place new piece
    switch (piece)
    {
    case PieceType::KING:
        board[xcord][ycord] = new KingPiece(xcord, ycord, color);
        break;
    case PieceType::BISHOP:
        board[xcord][ycord] = new BishopPiece(xcord, ycord, color);
        break;
    case PieceType::ROOK:
        board[xcord][ycord] = new RookPiece(xcord, ycord, color);
        break;
    case PieceType::KNIGHT:
        board[xcord][ycord] = new KnightPiece(xcord, ycord, color);
        break;
    case PieceType::PAWN:
        board[xcord][ycord] = new PawnPiece(xcord, ycord, color);
        break;
    case PieceType::QUEEN:
        board[xcord][ycord] = new QueenPiece(xcord, ycord, color);
        break;

    default:
        // should never get here
        std::cout
            << "Error unknown piece type"
            << piece << "\n";
        break;
    }
    // add new piece to board
    DEBUG &&std::cout << "Placed new piece: " << board[xcord][ycord]->toString() << " at location [" << board[xcord][ycord]->row << "," << board[xcord][ycord]->col << "]\n";
    return true;
}

int Board::pointEval() const
{
    int score = 0;

    for (auto &row : board)
    {
        for (auto &piece : row)
        {
            score += piece->value();
        }
    }
    DEBUG &&std::cout << "Point Eval : " << score << "\n";
    return score;
}

std::vector<Move> Board::legalMoves()
{
    std::vector<Move> moves;

    for (int row = 0; row < numRows; ++row)
    {
        for (int col = 0; col < numCols; ++col)
        {
            Piece *piece = board[row][col];
            if (piece && piece->getColor() == (isWhiteTurn ? Color::WHITE : Color::BLACK))
            {
                std::vector<Move> pieceMoves = piece->getLegalMoves(*this);
                moves.insert(moves.end(), pieceMoves.begin(), pieceMoves.end());
            }
        }
    }

    return moves;
}

std::ostream &operator<<(std::ostream &os, const Board &board)
{
    os << board.toString();
    return os;
}
