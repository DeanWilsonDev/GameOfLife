//
// Created by Dean Wilson on 12/6/2023.
//

#include "cell.h"
#include "life.h"
#include <iostream>




void cell::draw(int row, int col) const {
  // ANSI control command
  // escape[n;mH moves the cursor to rom n, column m
  // There are 1-based. i.e. row 1 is the first row

  std::cout << "\x1b[" << row + 1 << ";" << col + 1 << "H";
  std::cout << (alive ? liveCell : deadCell);
}