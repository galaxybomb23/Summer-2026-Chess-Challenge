# Devlog #2
I have been working on expanding the board class. This dev session was done on a 13 hr flight from Japan to the US, so I had to work on simplier things that don't require looking up documentation or using the internet. Also there was no working outlet so the dev session was only a few hours long 🥲.

## Development

### Board::initGame()
This funciton clears a board and initializes it to the starting position. Currently it is hard coded to the starting position, but I plan to add a FEN string parser to allow for arbitrary board setups.

### Board::clear()
basic function to clear the board removing all pieces

### Board::reset()
clearst the baord and places null pieces on all squares. This is used to reset the board to a blank state.

### Board::toString()
made some minor changes in how the board and pieces are printed to the console. 

### Board::isValidMoeve()
added skeleton code that does some basic checks to see if a move is valid. then checks the moving piece to see if it can make the move. NOTE: the pieces isValidMove() functions are not yet implemented, so this function will always return false for now.

### Board::PlacePiece()
This function deletes any existing piece on the square and places a new piece on the square. It also sets the piece's position to the square.

### Board::pointEval()
Sums the material value of all pieces on the board and returns the total score for both sides. 

### PieceTypeToString(PieceType piece)
added utility function to convert a piece type to a string for printing to the console.

### DEBUG Flag
added `DEBUG` flag that is used to print debug information to the console. 
```
DEBUG && std::cout << "Debug info" << std::endl; // basic example of how to use the debug flag. 
``` 
### Board::legalMoves()
itterates over all pieces on the board and calls each piece's legalMoves() function to get a list of all legal moves for that piece. It then returns a vector of all legal moves for the current board state. No big plans at the moment for this, but was easy to implement and will be useful for testing and debugging.

### New Commands
`:point || :p ` - prints the current material point score for both sides. 
`:list moves || :lm` - prints a list of all legal moves for the current board state.

### Piece::value()
basic lookup function that returns the material value of a piece based on its type.


## Future Plans
Now that I am back home and have internet access, I plan to work on implementing FEN parsing and exporting, and Algebraic notation parsing. I expect this will lead into legal move generation and validation for each piece, but will probably write another devlog before that.
