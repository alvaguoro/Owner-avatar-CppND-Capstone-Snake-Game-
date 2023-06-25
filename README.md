# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg

## Instructions

The game uses the arrow keys to be able to move the snake, as well as the Enter so when the snake dies we can restart the game.
The maximum score of the user is stored and kept between sessions so it´s never lost.

## Rubric

### 1 The project reads data from a file and process the data, or the program writes data to a file.

We store the maximum score achieved by the user in a .txt file that is read every time the program is opened, therefore keeping the maximum score.
The file management is done in main.cpp, before we create the game and after the game is finished.

### 2 The project uses Object Oriented Programming techniques.

We have created a class called ConcurrentQueue, this class is used to asure that we don´t run into race conditions when using the queues, encapsulating every lock so the developer does not need to see into this things.
The file is called concurrent_queue.h.

### 3 Templates generalize functions in the project.

The class ConcurrentQueue uses templates so we can use this queue in a lot of situations.

### 4 The project uses multithreading.

We use a thread for the key inputs where we are constantly pulling from a queue where we store all the movements of the snake so no movement is lost.
Line 23 of game.cpp we launch a thread that executes a function in which we have an "infinite" loop where we pull from a queue the directions that have been used by the user.

### 5 A mutex or lock is used in the project.

We use mutex to protect the data in the queue and to wait for the queue to not be empty.
This is within the ConcurrentQueue class.

### 6 A condition variable is used in the project.

We use a condition variable to wait for the queue to have elements.
This is within the ConcurrentQueue class.