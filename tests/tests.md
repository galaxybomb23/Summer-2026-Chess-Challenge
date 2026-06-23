**Test Null Piece Initialization:** Verifies that an empty board square initializes correctly with a null piece type and no color.
**Test Initial Board Setup:** Verifies that the default 8x8 board layout maps correctly to standard initial piece coordinates.
**Test Default FEN Import:** Verifies that importing the standard starting position FEN string correctly populates all pieces on the board.
**Test Arbitrary FEN Import:** Verifies that a valid custom FEN string populates an arbitrary middle-game board layout correctly.
**Test Malformed FEN Rejection:** Verifies that passing an invalid or broken FEN string triggers a graceful error or rejection.
**Test FEN Export Accuracy:** Verifies that exporting a current board state produces a valid, matching FEN string.
**Test Material Value Calculation:** Verifies that the system correctly scores the standard material point totals for both sides on the board.
**Test Starting Position Legal Moves:** Verifies that the initial game state generates exactly 20 legal moves for White.
**Test Pawn Regular Movement:** Verifies that pawns can move forward one or two squares correctly based on their starting rank.
**Test Rook Straight-Line Movement:** Verifies that rooks move correctly along ranks and files but are blocked by intervening pieces.
**Test Bishop Diagonal Movement:** Verifies that bishops move correctly along open diagonals but are blocked by intervening pieces.
**Test Knight L-Shaped Movement:** Verifies that knights jump over obstacles and move correctly in standard L-shapes.
**Test Queen Combined Movement:** Verifies that queens can move legally along both straight paths and diagonal paths.
**Test King Basic Movement:** Verifies that kings can move exactly one square in any direction.
**Test Blocked Move Rejection:** Verifies that a piece cannot move to a square occupied by a friendly piece.
**Test Capture Execution:** Verifies that a piece successfully moves to an opponent's square and removes the captured piece.
**Test Kingside Castling Validity:** Verifies that a king can execute a valid kingside castle when the path is clear and pieces haven't moved.
**Test Queenside Castling Validity:** Verifies that a king can execute a valid queenside castle when the path is clear and pieces haven't moved.
**Test Castling Prevention via Check:** Verifies that castling is rejected if the king is in check or passes through a threatened square.
**Test En Passant Capture:** Verifies that a pawn can legally capture an enemy pawn via en passant immediately after a two-square push.
**Test Pawn Promotion Option:** Verifies that a pawn reaching the furthest rank triggers a mandatory choice of promotion piece.
**Test Pin Enforcement:** Verifies that a piece is legally restricted from moving if its departure would expose its king to check.
**Test Check Detection:** Verifies that the engine correctly flags a state as "Check" when a king is actively threatened.
**Test Checkmate Detection:** Verifies that the game terminates with a checkmate flag when a king is in check with zero legal escapes.
**Test Stalemate Detection:** Verifies that the game terminates with a stalemate draw when a player has no legal moves but is not in check.
**Test Threefold Repetition Draw:** Verifies that a draw can be claimed or enforced when the exact same board position occurs three times.
**Test Fifty-Move Rule Draw:** Verifies that a draw is detected after fifty consecutive moves without a pawn advance or a piece capture.
**Test Insufficient Material Draw:** Verifies that the game flags a draw when remaining pieces cannot physically force a checkmate.
**Test Algebraic Notation Input Parsing:** Verifies that valid standard algebraic move commands are parsed correctly into internal coordinate movements.$
**Test Invalid Notation Rejection:** Verifies that malformed or impossible algebraic notation strings are gracefully rejected without crashing.$
