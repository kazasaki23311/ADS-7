// Copyright 2022 NNTU-CS
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>
#include "train.h"

int main() {
  std::srand(time(nullptr)); std::cout << std::setw(10) << "n"
    << std::setw(15) << "all false"
    << std::setw(15) << "all true"
    << std::setw(15) << "random"
    << std::setw(12) << "n^2"
    << std::endl;
  std::cout << std::string(67, '-') << std::endl;
  for (int n = 10; n <= 200; n += 10) {
    int64_t opFalse = 0;
    int64_t opTrue = 0;
    int64_t opRandom = 0;
    {
      Train train;
      for (int i = 0; i < n; i++)
        train.addCar(false);
      train.getLength();
      opFalse = train.getOpCount();
      }
    {
      Train train;
      for (int i = 0; i < n; i++)
        train.addCar(true);
      train.getLength();
      opTrue = train.getOpCount();
      }
    {
      int64_t totalRandom = 0;
      for (int trial = 0; trial < 5; trial++) {
        Train train;
        for (int i = 0; i < n; i++)
          train.addCar(std::rand() % 2);
        train.getLength();
        totalRandom += train.getOpCount();
        }
      opRandom = totalRandom / 5;
      }
    int64_t nSquared = n * n;
    std::cout << std::setw(10) << n
      << std::setw(15) << opFalse
      << std::setw(15) << opTrue
      << std::setw(15) << opRandom
      << std::setw(12) << nSquared
      << std::endl;
    }
  return 0;
}
