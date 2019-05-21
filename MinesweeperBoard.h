#ifndef MINESWEEPERBOARD_H
#define MINESWEEPERBOARD_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>




using namespace std;

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };


struct field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

class IntroController; // dek zapowiadajaca

class MinesweeperBoard
{

    field board[100][100];
    int width;
    int height;
    GameMode mode;
    GameState state;









public:


    explicit MinesweeperBoard(int width, int height, GameMode mode);
  void debug_display() const;
  int getBoardWidth() const;
  int getBoardHeight() const;
  int getMineCount() const;
  int countMines(int x, int y) const;
  bool hasFlag(int x, int y) const;
  void toggleFlag(int x, int y);
   void revealField(int x, int y);
   bool isRevealed(int x, int y) const;
   GameState getGameState() const;
   char getFieldInfo(int x, int y) const;
   bool isRightField(int x, int y) const;
   void odkrywanie(int x, int y);
   bool ifhasMine(int x, int y) const;
    void ResetBoard(int width, int height, GameMode mode);
   void SetBoard(int x, int y);
   void SetLvL(GameMode mode);
   void przegranaa();
   void SetEasy();
   void SetNormal();
   void SetHard();
   GameMode GetGameMode() const;





};
#endif // MINESWEEPERBOARD_H
