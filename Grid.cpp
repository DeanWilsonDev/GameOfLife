//
// Created by Dean Wilson on 12/6/2023.
//

#include "Grid.h"
#include <iostream>
namespace Life {

    void Grid::create(int row, int column) {
        cells[row][column].create();
    }


    // Draw all the cells, including the border
    void Grid::draw() {

        // ANSI control command
        // \x1b means "escape"
        // Escape[23 clears the screen and returns the cursor to the "home" position
        std::cout << "\x1b[23";

        for(int row = 0; row < row_max; ++row)
        {
            for(int column = 0; column < col_max; ++column){
                cells[row][column].draw(row, column);
            }
        }
    }

    // Populate the grid with cells, at random
    void Grid::randomize() {
        const int factor = 5;
        const int cutoff = RAND_MAX/factor;
        time_t now;
        time(&now);

        for(int row = 0; row < row_max; ++row)
        {
            for(int column = 0; column < col_max; ++column){
                if(rand()/cutoff == 0){
                    create(row, column);
                }
            }
        }
    }

    bool Grid::willSurvive(int row, int column) {
        if(!cells[row][column].isAlive()){
            /// There is no cell at this position
            return false;
        }

        // find the number of live neighbours in this cell
        //
        // X X X
        // X O X
        // X X X
        int neighbours = cells[row - 1][column - 1].isAlive() +
                         cells[row - 1][column].isAlive() +
                         cells[row - 1][column + 1].isAlive() +
                         cells[row][column - 1].isAlive() +
                         cells[row][column + 1].isAlive() +
                         cells[row + 1][column + 1].isAlive();

        if(neighbours < minNeighbours || neighbours > maxNeighbours){
            // Cell has died
            return false;
        }

        return true;
    }

    bool Grid::willCreate(int row, int column) {
        if(!cells[row][column].isAlive()){
            // There is no cell at this position
            return false;
        }

        // find the number of parents for this cell
        //
        // X X X
        // X O X
        // X X X
        int parents = cells[row - 1][column - 1].isAlive() +
                         cells[row - 1][column].isAlive() +
                         cells[row - 1][column + 1].isAlive() +
                         cells[row][column - 1].isAlive() +
                         cells[row][column + 1].isAlive() +
                         cells[row + 1][column + 1].isAlive();

        if(parents < minParents || parents > maxParents){
            // Cannot create cell here
            return false;
        }

        return true;
    }

    void Grid::update(const Life::Grid &next) {
        for(int row = 1; row < row_max; ++row){
            for(int column = 1; column < col_max; ++column){
                cells[row][column] = next.cells[row][column];
            }
        }
    }


    void calculate(Grid& old_generation, Grid& new_generation){

        for(int row = 1; row < row_max; ++row){
            for(int column = 1; column < col_max; ++column){
               // Will this live cell survive to the next generation?
               if(old_generation.willSurvive(row, column)){
                   new_generation.create(row, column);
               }
               // Will this unpopulated cell be populated in the next generation?
               else if(old_generation.willCreate(row, column)){
                   new_generation.create(row,column);
               }
            }
        }
    }

} // Life