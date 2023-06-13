//
// Created by Dean Wilson on 12/6/2023.
//

#include <iostream>
#include "grid.h"

#include "ansi_escapes.h"

int main(int argc, char *argv[]) {
  std::cout << "Conway's Game of life" << std::endl;
  std::cout << "Press the return key to display each generation\n";

  // wait for user to press the return key
  std::cin.get();

  // Uncomment if running in Windows Console
  // Enable ANSI escape codes on Windows
  setupConsole();

  // grid for the first generation
  grid current_generation;

  // populate the cells at random
  current_generation.randomize();

  while (true) {

    // Draw the current generation
    current_generation.draw();

    // wait for user to press the return key
    std::cin.get();

    // Gid for the next generation
    grid next_generation;

    // Populate the cells in the next generation
    calculate(current_generation, next_generation);

    // Update to the next generation
    current_generation.update(next_generation);
  }

  // Uncomment if running in Windows Console
  // Restore console on Windows
   restoreConsole();
}
