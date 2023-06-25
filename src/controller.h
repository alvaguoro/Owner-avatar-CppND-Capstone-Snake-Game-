#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "concurrent_queue.h"

class Controller {
 public:
  bool HandleInput(bool &running, Snake &snake);
  void CheckInputQueue(Snake &snake);
  void StopInputThread()
  {
    shouldInputThreadRun = false;
    _queue.release();
  }
  ConcurrentQueue<Snake::Direction> _queue;
  
 private:
  void ChangeDirection(Snake &snake, Snake::Direction input) const;
  bool shouldInputThreadRun = true;
};

#endif