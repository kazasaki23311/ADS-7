// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car* anotherCar = new Car;
  anotherCar->light = light;
  anotherCar->next = nullptr;
  anotherCar->prev = nullptr;
  if (first == nullptr) {
    first = anotherCar;
    first->next = first;
    first->prev = first;
  } else {
    Car* lastCar = first->prev;
    lastCar->next = anotherCar;
    first->prev = anotherCar;
    anotherCar->next = first;
    anotherCar->prev = lastCar;
  }
}

int Train::getLength() {
  if (first == nullptr) return 0;
  countOp = 0;
  first->light = true;
  int step = 1;
  Car* now = first;
  while (true) {
    for (int i = 0; i < step; i++) {
      now = now->next;
      countOp++;
      }
    if (!now->light) {
      now->light = true;
      for (int i = 0; i < step; i++) {
        now = now->prev;
        countOp++;
        }
      step = 1;
      continue;
      }
    bool allLight = true;
    Car* check = now;
    for (int i = 0; i < step; i++) {
      check = check->prev;
      countOp++;
      if (!check->light) {
        allLight = false;
        break;
        }
      }
    if (allLight) {
      return step;
      }
    for (int i = 0; i < step; i++) {
      now = now->prev;
      countOp++;
    }
    step++;
    }
}

int Train::getOpCount() { return countOp; }
