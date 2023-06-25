#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Snake &snake, Snake::Direction input) const {

  Snake::Direction opposite;

  switch(input)
  {
    case Snake::Direction::kUp:
      opposite = Snake::Direction::kDown;
      break;

    case Snake::Direction::kDown:
      opposite = Snake::Direction::kUp;
      break;

    case Snake::Direction::kLeft:
      opposite = Snake::Direction::kRight;
      break;

    case Snake::Direction::kRight:
      opposite = Snake::Direction::kLeft;
      break;
  }

  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

bool Controller::HandleInput(bool &running, Snake &snake) {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          _queue.push(Snake::Direction::kUp);
          break;

        case SDLK_DOWN:
          _queue.push(Snake::Direction::kDown);
          break;

        case SDLK_LEFT:
          _queue.push(Snake::Direction::kLeft);
          break;

        case SDLK_RIGHT:
          _queue.push(Snake::Direction::kRight);
          break;
        
        case SDLK_RETURN:
          if(!snake.alive)
            return true;
          break;
      }
    }
  }

  return false;
}

void Controller::CheckInputQueue(Snake &snake)
{
  while(shouldInputThreadRun)
  {
    _queue.wait(shouldInputThreadRun);
    auto dir = _queue.pop();

    ChangeDirection(snake, dir);
  }

  // if(!_queue.empty())
  // {
  //   auto dir = _queue.pop();

  //   ChangeDirection(snake, dir);
  // }
}