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
  Car* start = first;
  start->light = true;
  int step = 2;
  while (true) {
    Car* now = start;
    for (int i = 0; i < step; i++) {
      now = now->next;
      countOp++;
      }
    if (!now->light) {
      now->light = true;
      step = 2;
      continue;
      }
    now->light = false;
    for (int i = 0; i < step; i++) {
      now = now->prev;
      countOp++;
      }
    if (!start->light) {
      return step;
      }
    step++;
    }
}

int Train::getOpCount() { return countOp; }
