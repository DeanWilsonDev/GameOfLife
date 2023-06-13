//
// Created by Dean Wilson on 12/6/2023.
//

#ifndef GAMEOFLIFE_GRID_H
#define GAMEOFLIFE_GRID_H

#include <string>
#include <vector>
#include <cstdlib>

#include "cell.h"
#include "life.h"

class grid {

  // The cells on the screen
  // We have a border consisting of inactive cells
  // These are used in the calculation for the next generation of cells,
  // but are not displayed on the screen
  cell cells[rowMax + 2][colMax + 2];

public:
  void create(int row, int column);

  void draw();

  void randomize();

  bool willSurvive(int row, int column);

  bool willCreate(int row, int column);

  void update(const grid &next);
};

// Calculate which cells survive to the next generation and which are born
void calculate(grid &old_generation, grid &new_generation);


#endif //GAMEOFLIFE_GRID_H
