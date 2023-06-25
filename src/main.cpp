#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include <fstream>

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;

  std::ifstream fileRead("maxscore.txt");
  int maxScore;

  if(fileRead.is_open())
  {
    fileRead >> maxScore;
    fileRead.close();
  }

  Game game(kGridWidth, kGridHeight);

  game.SetMaxScore(maxScore);

  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";

  std::ofstream fileWrite("maxscore.txt", std::ios::trunc);

  if(fileWrite.is_open())
  {
    fileWrite << game.GetMaxScore();
    fileWrite.close();
  }

  return 0;
}