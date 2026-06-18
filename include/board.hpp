#ifndef BOARD_HPP
#define BOARD_HPP

#include "common.hpp"

#include <memory>
#include <string>

class Board
{
public:
    // this constructor will build a standard chess board with no pieces.
    Board(int numRows = 8, int numCols = 8);

    // this constructor will build a board based on a FEN string. it supports abitratray board size based on fen string.
    Board(std::string fen);
    ~Board();

    // string representation of the board. This will be used for rendering the board and for debugging purposes. The board will use Unicode characters for pieces and blank spaces. Once TUI is involved this may change
    std::string toString() const;

    // this clears the board to the default starting position 
    void reset();

    // This clears a board of any pieces
    void clear(); 

    // This is used to validate a move against the board state
    bool isValidMove(const Move &move) const;

    // This exectutes a move on the board. This function will validate the move and return false if the move is invalid. If the move is valid, it will update the board state and return true. It will also update the move history and turn number.
    bool executeMove(const Move &move);

    // this will undo the last move on the board. It will update the board state, move history, and turn number accordingly. It will return false if there are no moves to undo.
    void undoMove();

    // this is used for board building. it does no validation and just places pieces on the board.
    void placePiece(Color color, PieceType piece, int xcord, int ycord);

    // this is used to initialize a new board or wipe the current board to a new state. it will return false if the FEN string is invalid. it will return true if the FEN string is valid and the board state has been updated. If the FEN is of a differnet board size it will update the board size accordingly. This will also reset the move history and turn number.
    bool importFEN(std::string input);

    // this is for exporting the board state
    void printFEN() const;

    // this is to determine who is winning based on material
    int pointEval() const;


    friend std::ostream &operator<<(std::ostream &os, const Board &board);

private:
    std::vector<std::vector<Piece *>> board;
    std::vector<Move> moveHistory;

    bool isWhiteTurn;
    bool canWhiteCastleKingside;
    bool canWhiteCastleQueenside;
    bool canBlackCastleKingside;
    bool canBlackCastleQueenside;
    int turnNumber;

    int numRows;
    int numCols;
};

#endif
