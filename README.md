# ConsoleChess
Pet-project for practicing C++ skills

## System requirements
- OS: Windows 10 or higher
- Visual Studio 2019 or higher

## Screenshot of console application
  ![image](https://github.com/miha89507/ConsoleChess/assets/35353977/dc039c59-11ca-4b75-a305-3171ccb7f354)

## Description
This console application was created as part of developing skills in using the C++ language, without Internet access, with a reference book, and does not pretend to be original or implement great ideas, and if I find myself on a desert island with a laptop in my hands and an installed compiler, then I can spend my remaining days to play chess with yourself.

**NOTE**: I would like to note right away that at this iteration of the application (the original code appeared in January 2024), capturing on the pass is not implemented, and there is also no check for the possibility of moving a specific piece, so in theory you can go anywhere within the chessboard.

This project covered:
- working with pointers;
- working with OOP.

## How it works
On top of the chessboard there are pieces in the form of symbols: 1 - Soldier, U - Fort, 2 - Horse, 1 - Elephant, W - Queen, V - King.

Black pieces are marked *.

Implemented move recording history:

![image](https://github.com/miha89507/ConsoleChess/assets/35353977/368ebe36-23a1-4489-b373-b04f9ad02c19)

**WARNING!!!**
After any move click [ENTER].

To make a move, you need to write a string in the following format: **{** piece symbol **}** **{** current cell of the piece's position **}** **{** desired cell of the piece's position **}**:

![image](https://github.com/miha89507/ConsoleChess/assets/35353977/8597d570-0eca-4429-b382-5b3b8867a3d4)

![image](https://github.com/miha89507/ConsoleChess/assets/35353977/1d6cc599-16ac-43d0-ad86-8335f2421ae5)

Long/short castling has been implemented for the king: 0-0/0-0-0:

![image](https://github.com/miha89507/ConsoleChess/assets/35353977/0956a219-a870-4d3b-9989-e6ee363c3ffc) ![image](https://github.com/miha89507/ConsoleChess/assets/35353977/859be4e0-9c92-4ac7-aca3-af4dfc2ed27b)


A promotion has been implemented for the pawn on the opponent's last square:

![image](https://github.com/miha89507/ConsoleChess/assets/35353977/cc3dfc61-7e26-4010-979d-b45c942d0a11)

The game is designed for two “honest” players on one computer.
