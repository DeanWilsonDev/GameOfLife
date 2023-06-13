//
// Created by Dean Wilson on 12/6/2023.
//

#ifndef GAMEOFLIFE_CELL_H
#define GAMEOFLIFE_CELL_H

class cell {
  bool alive;
public:
  cell() : alive(false) {}

  void draw(int row, int col) const;

  void create() {
    alive = true;
  }

  void erase() {
    alive = false;
  }

  bool isAlive() const {
    return alive;
  }
};


#endif //GAMEOFLIFE_CELL_H
