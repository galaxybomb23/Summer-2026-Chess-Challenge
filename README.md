# Summer-2026-Chess-Challenge
This is the Eta kappa Nu Summer chess Challenge

The Summer Chess Challenge is a learning-first build challenge for friends who want to sharpen their programming skills, explore language design tradeoffs, and create fun content for the HKN GitHub and YouTube presence.

Each participant will build a chess platform in a different programming language, document their work throughout the summer, and optionally extend their project into networking and engine play.


##  Overview Video 
[![Watch the video](https://img.youtube.com/vi/Rn8EeuiSDS4/hqdefault.jpg)](https://www.youtube.com/watch?v=Rn8EeuiSDS4)
***


## Core Goals

1. Have a fun summer challenge among friends.
2. Improve programming skill through hands-on project work.
3. Create useful and interesting content for the HKN GitHub and YouTube channels.

## Timeline

All deadlines are defined in EST.

| Milestone | Date |
| --- | --- |
| Registration opens | Thursday, May 28, 2026 |
| Registration closes | Saturday, May 30, 2026 at 11:59 PM EST |
| Networking RFC discussion window | June 21-28, 2026 |
| Networking protocol vote | June 28, 2026 |
| Challenge build period ends | Friday, July 31, 2026 |
| Leaderboard/results publication | Monday, August 3, 2026 (`TBD` format) |

## General Rules

- Exclusivity: no more than two developers may use the same programming language. Languages are assigned on a first-come, first-served basis.
- Target stack: permitted languages include, but are not limited to, Rust, Go, C++, Zig, OCaml, Haskell, Python, Swift, Java, C#, TypeScript, Matlab, and Kotlin.
- Prohibited dependencies: third-party chess-specific packages, engines, rules libraries, or move-generation helpers are not allowed.
- Allowed exceptions: helper libraries that do not implement chess logic are allowed, including terminal coloring libraries, platform console helpers, and testing frameworks.
- External engines and services: no project may query Stockfish, Komodo, cloud-hosted chess engines, or external chess databases for move generation or evaluation.
- Challenge focus: this is primarily an educational and documentation-heavy challenge, not a subjective "best overall project" competition.

## Language Allocation

Fill this table in as registrations are received.

| Language | Slot 1 | Slot 2 |
| --- | --- | --- |
| Rust | [Thomas O'Donnell](https://github.com/iBoot32) | Open |
| Go | Open | Open |
| C | [Thomas Munson](https://github.com/TRMunson7) | Open |
| C++ | [Elijah Jorgensen](https://github.com/galaxybomb23) | Open |
| Zig | Open | Open |
| OCaml | Open | Open |
| Haskell | Open | Open |
| Python | [Alex Tauriainen](https://github.com/Aarynda)  | Open |
| Swift | Open | Open |
| Java | Open | Open |
| C# | Open | Open |
| TypeScript | Open | Open |
| Matlab | [Arjun Siderys](https://github.com/asiderys) | Open |
| Kotlin | Open | Open |
| gdscript | [Asher Sprigler](https://github.com/Legitimatemuffin) | Open |
| Other | Open | Open |

## Phase 1: Registration

Registration begins the challenge and establishes the initial project direction.

Each participant must complete this Form: https://forms.gle/z1a5zPYiAnU4f2naA

After registration is confirmed:

- The participant will be listed in this master challenge repo
- The participant should fork this repository to host their own project work
- The participant will complete development in their fork rather than on a shared branch in the master repo

Recommended registration tasks:

- Fork the master challenge repository
- Create an initial milestone board or task list
- Add a starter `README.md` with setup intentions and goals

The master repository will serve as the central hub for:

- Challenge rules and timeline
- Language allocation tracking
- Registration and participant records
- Shared discussion for the networking RFC
- Final challenge-wide documentation such as `protocol.md`

## Phase 2: Build a TUI Chess Platform

Phase 2 is the main implementation phase. Each participant must create a terminal-based chess platform and document its development throughout the challenge.

### Required Intro Video

Each participant must publish a video of at least 10 minutes that covers:

- Core design philosophy for the project
- Language-specific development style or paradigm choices such as OOP, functional design, or data-oriented design
- Preliminary architecture and implementation plan
- Basic instructions for how to build and run the application

Participants are encouraged, but not required, to create additional setup videos for their language and toolchain, such as:

- Installing `gcc` on Windows
- Creating a `Makefile`
- Setting up a Rust toolchain
- Running tests in the chosen environment

### Weekly Development Logs

Each participant must maintain:

- A weekly written development log
- A weekly progress video

Weekly progress videos will be published on the HKN YouTube channel as Devlogs.

Each weekly video should follow this structure:

1. The first part explains the programming ideas, chess theory, or implementation plan for the week.
2. The second part demonstrates code, working features, or active development progress.

The exact submission, review, and publishing process for these Devlogs will be defined more formally over the weekend.

### Core Requirements

Every Phase 2 project must provide the following minimum functionality:

- A text user interface (TUI) chess platform
- Import of a board state from FEN
- Export of the current board state to FEN
- Board rendering from a valid arbitrary board state
- Move input using algebraic notation after the initial state is established
- Game logging in algebraic notation
- Legal move generation for the current board state
- Rejection of invalid moves
- Detection of check, checkmate, and stalemate
- Support for castling
- Support for en passant
- Support for pawn promotion
- Detection of practical draw conditions:
  - threefold repetition
  - fifty-move rule
  - insufficient material
- A command or display for all currently available legal moves
- A command or display for standard material point values
- Optional display of a custom developer-specific point system if clearly separated from the standard one
- Graceful rejection of malformed FEN strings or illegal positions
- Clear reporting of the game termination reason

### Stretch Goals

Stretch goals are optional quality-of-life or validation ideas. They are not required for challenge completion.

- `perft` support for move-generation and rules-validation testing
- Optional timer or chess clock support
- PGN export
- Undo support or move replay tools
- Enhanced board styling or TUI quality-of-life improvements

## Phase 3: Networking

Phase 3 expands the project from a local chess platform into a networked multiplayer application.

### Protocol Design

The networking API and protocol will remain intentionally unspecified until registration closes. After that, participants will discuss and define the protocol through a lightweight RFC-style process.

- Public discussion window: June 21-28, 2026
- Discussion venue: public form or discussion thread in the GitHub repo
- Vote date: June 28, 2026
- Final output: a frozen `protocol.md` file describing the agreed protocol

The RFC process should settle:

- Transport choice
- Message format
- Handshake and versioning expectations
- Game-state synchronization approach
- Error handling expectations

### Protocol Implementation

After `protocol.md` is finalized, each participant must extend the project so that:

- Two users can connect and play a standard untimed chess game
- Both clients remain synchronized on board state and turn order
- Invalid or out-of-turn messages are rejected clearly
- Disconnects or connection failures are surfaced clearly to the user

## Optional Phase 4: Chess Engine

Phase 4 is optional and should not affect completion of the core challenge.

Participants may implement a chess engine or algorithm that can:

- Play locally against a user
- Potentially interact through the networking layer if compatible with the final protocol

The leaderboard/results publication is scheduled for Monday, August 3, 2026, but the exact ranking format is still `TBD`.

If an engine competition is adopted later, its rules should be frozen in a separate `engine_rules.md` document covering items such as:

- Time controls
- Hardware fairness expectations
- Pairing format
- Match and bracket structure

## Required Project Deliverables

Each participant project should include a project-level `README.md` with:

- Setup instructions
- Build and run instructions
- Supported commands
- A short architecture summary

Each participant is expected to produce:

- Registration form submission
- Intro/design video
- Weekly written dev logs
- Weekly progress videos
- Final project state by July 31, 2026
- Networking extension after `protocol.md` is frozen

## Shared Validation Scenarios

Participants should validate their implementations against a common set of scenarios.

- Starting-position legal move count
- Kingside castling
- Queenside castling
- En passant capture
- Promotion with explicit piece choice
- Checkmate detection
- Stalemate detection
- Threefold repetition draw
- Fifty-move-rule draw
- Insufficient-material draw
- Invalid algebraic notation rejection
- FEN import/export round-trip

If a project implements `perft`, participants are encouraged to publish benchmark positions and known expected node counts as a logic-validation aid.

## Notes

- Stretch goals should be viewed as optional QoL or verification features rather than requirements.
- Any future ranking based on algorithm head-to-head matches belongs to the optional engine track, not the core project requirements.
- The most important deliverables are a solid implementation, consistent dev logs, and useful educational content for others to follow.
