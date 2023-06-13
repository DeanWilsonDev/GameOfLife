//
// Created by Dean Wilson on 12/6/2023.
//

#include "Life.h"
#include <iostream>
#include "Grid.h"
#include "Cell.h"

namespace Life {

    int main(int argc, char *argv[]) {
        std::cout << "Conway's Game of Life" << std::endl;


        // wait for user to press the return key
        std::cin.get();

        // grid for the first generation
        Grid current_generation;

        // populate the cells at random
        current_generation.randomize();

        while (true) {

            // Draw the current generation
            current_generation.draw();

            // wait for user to press the return key
            std::cin.get();

            // Gid for the next generation
            Grid next_generation;

            // Populate the cells in the next generation
            calculate(current_generation, next_generation);

            // Update to the next generation
            current_generation.update(next_generation);
        }
        
        return 0;
    }

}
