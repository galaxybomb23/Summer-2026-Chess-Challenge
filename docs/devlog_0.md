# Devlog #0
This devlog will cover the preliminary plans for the project and include basic ideas for how the application will be structured.

## About Me
- 2026 HKN Alum
- Used to use C++ for computer vision/robotics projects and python libraries.
- want to get back into C++ and learn more about chess engines.

## The Runtime
The runtime will be responsible for managing user input mild parsing and executing commands on the board. My plan is to use simple C++ I/O to achieve this, and a infinite loop to keep the application running until the user decides to quit.

I plan to use ":" as my escape character for commands, so for example ":l" would list all avalible moves "e4" would attempt to move a piece to e4. I will also implement some basic commands for quitting the application, undoing moves, resetting the board, and loading FEN strings.


## The Board
The board will be the main component of the application. It will hold the game state in a 2D vector of pieces. It will also keep track of the current player and any other relevant information about the game state.

The board could utilize bit boards to represent the game state more efficiently, but my design is OOP focused so I will be using Classes to represent the pieces and the board.

The board will also keep a history of moves to allow for undo functionality and to keep track of the game state to be printed to the user.

Basic Class Idea atm:
```cpp
class Board {
    std::vector<std::vector<Piece*>> board;
    std::vector<Move> moveHistory;
    
    // other relevant game state information
    bool isWhiteTurn;
    bool canWhiteCastleKingside;
    bool canWhiteCastleQueenside;
    bool canBlackCastleKingside;
    bool canBlackCastleQueenside;

    // methods for managing the board state, validating moves, and executing moves
    void updateBoard(const Move& move);
    bool isValidMove(const Move& move);
    void executeMove(const Move& move);
    void undoMove();

    // overload the << operator to print the board state to the user
    friend std::ostream& operator<<(std::ostream& os, const Board& board);

    // and probalby much more as I continue to develop the application

};

Struct Move {
    int fromX, fromY;
    int toX, toY;
    Piece* pieceMoved;
    Piece* pieceCaptured; // nullptr if no piece was captured, may also use for castling and en passant
    int moveNumber; // for move history and undo functionality
    MoveType moveType; // NORMAL, CASTLING, EN_PASSANT, PROMOTION

};

ENUM MoveType {
    NORMAL,
    CASTLING,
    EN_PASSANT,
    PROMOTION
};
```

## The Pieces
There will be an abstract base class for pieces, and then derived classes for each type of piece (Pawn, Rook, Knight, Bishop, Queen, King). Each piece will have its own movement rules and will be responsible for validating moves. 

More importantly, the move validation logic will take in a ref to the board. this is some of the only logic that will implement processing. I had a prior design where the board ref would be a piece varible, but I think that runs into an issue of circular dependencies. By having the board pass itself into the piece for move validation, I can avoid this issue and keep the pieces as simple data objects.

By in large the pieces are a Data object, and will have minimal gameplay methods.

Basic Class Idea atm:
```cpp
class Piece {
    bool isWhite; 
    PieceType type; // PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING, NULL

    // methods for validating moves and other piece-specific logic
    virtual bool isValidMove(const Move& move, const Board& board) = 0;
    virtual std::vector<Move> getPossibleMoves(const Board& board) = 0; 

    // overload the << operator to print the piece to the user
    friend std::ostream& operator<<(std::ostream& os, const Piece& piece);
};

ENUM PieceType {
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING,
    NONE // for empty squares
};

```

## Chess Engine
I got no idea at this point perhaps Beta Tuning or some naive Minimax implementation.


# Dev Plan

- Implement the Base board rendering of NUll pieces
- Create skeleton Code of all pieces
- Impliment render of all board pieces
- Impliment FEN PArsing to build board
- Prolly go way off track into UI design with FTXUI
- Impliment move parsing to execute moves on the board
- Impliment move validation logic for all pieces
- Impliment move history and undo functionality
- Add additional features like castling, en passant, and promotion
- add supplimentary features

NOTE: this is '*in order*' but I will likely jump around as I work on the project.
