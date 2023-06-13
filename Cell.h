//
// Created by Dean Wilson on 12/6/2023.
//

#ifndef CPP_KATA_CELL_H
#define CPP_KATA_CELL_H

namespace Life{

    class Cell {
        bool alive;
    public:
        Cell();
        void draw(int row, int col) const;
        void create();
        void erase();
        bool isAlive() const;
    };
}



#endif //CPP_KATA_CELL_H
