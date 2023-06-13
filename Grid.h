//
// Created by Dean Wilson on 12/6/2023.
//

#ifndef CPP_KATA_GRID_H
#define CPP_KATA_GRID_H
#include "Life.h"
#include "Cell.h"
namespace Life {

    class Grid {

        // The cells on the screen
        // We have a border consisting of inactive cells
        // These are used in the calculation for the next generation of cells,
        // but are not displayed on the screen
        Cell cells[row_max+2][col_max+2];

    public:
        void create(int row, int column);

        void draw();

        void randomize();

        bool willSurvive(int row, int column);

        bool willCreate(int row, int column);

        void update(const Grid& next);
    };

    // Calculate which cells survive to the next generation and which are born
    void calculate(Grid& old_generation, Grid& new_generation);

} // Life

#endif //CPP_KATA_GRID_H
