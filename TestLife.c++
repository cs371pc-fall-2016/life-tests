// --------------------------
// projects/life/TestLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include "gtest/gtest.h"

#include "Life.h"

using namespace std;

////// ConwayCell Tests ////////

// ConwayCell Constructors
TEST(LifeFixture, conway_dflt_constr_1) {
  ConwayCell c = ConwayCell();
  ASSERT_EQ(c._a, false);
}
TEST(LifeFixture, conway_arg_constr_1) {
  ConwayCell c = ConwayCell(true);
  ASSERT_EQ(c._a, true);
}
TEST(LifeFixture, conway_arg_constr_2) {
  ConwayCell c = ConwayCell(false);
  ASSERT_EQ(c._a, false);
}
TEST(LifeFixture, conway_cpy_constr_1) {
  ConwayCell cc = ConwayCell(false);
  ConwayCell c = cc;
  ASSERT_EQ(cc._a, false);
}
TEST(LifeFixture, conway_cpy_constr_2) {
  ConwayCell cc = ConwayCell(true);
  ConwayCell c = cc;
  ASSERT_EQ(cc._a, true);
}
// Conway update
TEST(LifeFixture, conway_update_1) {
  ConwayCell cc = ConwayCell();
  cc.update(5);
  ASSERT_EQ(cc._a, false);
}
TEST(LifeFixture, conway_update_2) {
  ConwayCell cc = ConwayCell();
  cc.update(3);
  ASSERT_EQ(cc._a, true);
}
TEST(LifeFixture, conway_update_3) {
  ConwayCell cc = ConwayCell(true);
  cc.update(2);
  ASSERT_EQ(cc._a, true);
}
TEST(LifeFixture, conway_update_4) {
  ConwayCell cc = ConwayCell(true);
  cc.update(5);
  ASSERT_EQ(cc._a, false);
}
TEST(LifeFixture, conway_update_5) {
  ConwayCell cc = ConwayCell(true);
  cc.update(0);
  ASSERT_EQ(cc._a, false);
}

// Conway isNeighbor
TEST(LifeFixture, conway_is_neighbor_1) {
  ConwayCell cc = ConwayCell();
  ASSERT_EQ(cc.isNeighbor(3), true);
}
TEST(LifeFixture, conway_is_neighbor_2) {
  ConwayCell cc = ConwayCell();
  ASSERT_EQ(cc.isNeighbor(0), true);
}
TEST(LifeFixture, conway_is_neighbor_3) {
  ConwayCell cc = ConwayCell();
  ASSERT_EQ(cc.isNeighbor(4), true);
}

// Conway toChar
TEST(LifeFixture, conway_to_char_1) {
  ConwayCell cc = ConwayCell();
  ASSERT_EQ(cc.toChar() == '.', cc._a == false);
}
TEST(LifeFixture, conway_to_char_2) {
  ConwayCell cc = ConwayCell(true);
  ASSERT_EQ(cc.toChar(), '*');
}
TEST(LifeFixture, conway_to_char_3) {
  ConwayCell cc = ConwayCell();
  ASSERT_EQ(cc.toChar(), '.');
}

// Conway isAlive
TEST(LifeFixture, conway_is_alive_1) {
  ConwayCell cc = ConwayCell();
  ASSERT_EQ(cc.isAlive(), false);
}
TEST(LifeFixture, conway_is_alive_2) {
  ConwayCell cc = ConwayCell(true);
  ASSERT_EQ(cc.isAlive(), true);
}

////// FredkinCell Tests ////////

// FredkinCell Constructors
TEST(LifeFixture, fredkin_dflt_constr_1) {
  FredkinCell f = FredkinCell();
  ASSERT_EQ(f._a, false);
}
TEST(LifeFixture, fredkin_dflt_constr_2) {
  FredkinCell f = FredkinCell();
  ASSERT_EQ(f.age, 0);
}
TEST(LifeFixture, fredkin_arg_constr_1) {
  FredkinCell f = FredkinCell(false);
  ASSERT_EQ(f._a, false);
}
TEST(LifeFixture, fredkin_arg_constr_2) {
  FredkinCell f = FredkinCell(true);
  ASSERT_EQ(f._a, true);
}
TEST(LifeFixture, fredkin_arg_constr_3) {
  FredkinCell f = FredkinCell(false);
  ASSERT_EQ(f.age, 0);
}
TEST(LifeFixture, fredkin_arg_constr_4) {
  FredkinCell f = FredkinCell(true);
  ASSERT_EQ(f.age, 0);
}
TEST(LifeFixture, fredkin_cpy_constr_1) {
  FredkinCell ff = FredkinCell(false);
  FredkinCell f = ff;
  ASSERT_EQ(f._a, false);
}
TEST(LifeFixture, fredkin_cpy_constr_2) {
  FredkinCell ff(true);
  FredkinCell f = ff;
  ASSERT_EQ(f._a, true);
}
TEST(LifeFixture, fredkin_cpy_constr_3) {
  FredkinCell ff(false);
  FredkinCell f = ff;
  ASSERT_EQ(f.age, 0);
}
TEST(LifeFixture, fredkin_cpy_constr_4) {
  FredkinCell ff(true);
  FredkinCell f = ff;
  ASSERT_EQ(f.age, 0);
}
// FredkinCell update
TEST(LifeFixture, fredkin_update_1) {
  FredkinCell f = FredkinCell(true);
  f.update(1);
  ASSERT_EQ(f.age, 1);
}
TEST(LifeFixture, fredkin_update_2) {
  FredkinCell f = FredkinCell(true);
  f.update(2);
  ASSERT_EQ(f._a, false);
}
TEST(LifeFixture, fredkin_update_3) {
  FredkinCell f = FredkinCell(true);
  f.update(2);
  ASSERT_EQ(f.age, 0);
}
TEST(LifeFixture, fredkin_update_4) {
  FredkinCell f = FredkinCell(false);
  f.update(1);
  ASSERT_EQ(f.age, 0);
}
TEST(LifeFixture, fredkin_update_5) {
  FredkinCell f = FredkinCell(true);
  f.update(1);
  ASSERT_TRUE(f.age == 1);
  AbstractCell *acp = f.update(1);
  if (ConwayCell *const ccp = dynamic_cast<ConwayCell *>(acp)) {
    ConwayCell c = *ccp;
    ASSERT_TRUE(c.isAlive());
  } else {
    ConwayCell *cccp = dynamic_cast<ConwayCell *>(acp);
    ASSERT_NE(cccp, nullptr);
  }
}
TEST(LifeFixture, fredkin_update_6) {
  FredkinCell f = FredkinCell(true);
  AbstractCell *ac = f.update(1);
  ASSERT_EQ(ac, nullptr);
}
TEST(LifeFixture, fredkin_update_7) {
  FredkinCell f = FredkinCell(true);
  f.update(1);
  f.update(2);
  f.update(1);
  ASSERT_EQ(f.toChar(), '1');
}
TEST(LifeFixture, fredkin_update_8) {
  FredkinCell f = FredkinCell(true);
  f.update(1);
  f.update(2);
  f.update(1);
  f.update(1);
  ASSERT_EQ(f.toChar(), '2');
}
// FredkinCell isNeighbor
TEST(LifeFixture, fredkin_is_neighbor_1) {
  FredkinCell f = FredkinCell();
  const bool b = f.isNeighbor(1);
  ASSERT_EQ(b, true);
}
TEST(LifeFixture, fredkin_is_neighbor_2) {
  FredkinCell f = FredkinCell();
  const bool b = f.isNeighbor(2);
  ASSERT_EQ(b, false);
}
TEST(LifeFixture, fredkin_is_neighbor_3) {
  FredkinCell f = FredkinCell();
  const bool b = f.isNeighbor(3);
  ASSERT_EQ(b, true);
}

// FredkinCell toChar
TEST(LifeFixture, fredkin_to_char_1) {
  FredkinCell f = FredkinCell(true);
  ASSERT_EQ(f.toChar(), '0');
}
TEST(LifeFixture, fredkin_to_char_2) {
  FredkinCell f = FredkinCell(true);
  f.update(1);
  ASSERT_EQ(f.toChar(), '1');
}
TEST(LifeFixture, fredkin_to_char_3) {
  FredkinCell f = FredkinCell(false);
  ASSERT_EQ(f.toChar(), '-');
}
TEST(LifeFixture, fredkin_to_char_4) {
  FredkinCell f = FredkinCell(true);
  for (int i = 0; i < 10; ++i) {
    f.update(1);
  }
  ASSERT_EQ(f.toChar(), '+');
}
TEST(LifeFixture, fredkin_is_alive_1) {
  FredkinCell f = FredkinCell(false);
  ASSERT_EQ(f.isAlive(), false);
}
TEST(LifeFixture, fredkin_is_alive_2) {
  FredkinCell f = FredkinCell(true);
  ASSERT_EQ(f.isAlive(), true);
}
/////////// Cell Tests

// Cell Constructors
TEST(LifeFixture, cell_dflt_constr_1) {
  Cell c = Cell();
  ASSERT_EQ(c.isAlive(), false);
}
TEST(LifeFixture, cell_arg_constr_1) {
  FredkinCell fc = FredkinCell(false);
  Cell c = Cell(&fc);
  ASSERT_EQ(c.isAlive(), false);
}
TEST(LifeFixture, cell_arg_constr_2) {
  ConwayCell cc = ConwayCell(true);
  Cell c = Cell(&cc);
  ASSERT_EQ(c.isAlive(), true);
}
TEST(LifeFixture, cell_arg_constr_3) {
  ConwayCell cc = ConwayCell(false);
  Cell c = Cell(&cc);
  ASSERT_EQ(c.isAlive(), false);
}
TEST(LifeFixture, cell_arg_constr_4) {
  FredkinCell fc = FredkinCell(true);
  Cell c = Cell(&fc);
  ASSERT_EQ(c.isAlive(), true);
}
TEST(LifeFixture, cell_cpy_constr_1) {
  FredkinCell fc = FredkinCell(false);
  Cell c = Cell(&fc);
  Cell copy = c;
  ASSERT_EQ(copy.isAlive(), false);
}
TEST(LifeFixture, cell_cpy_constr_2) {
  ConwayCell cc = ConwayCell(false);
  Cell c = Cell(&cc);
  Cell copy = c;
  ASSERT_EQ(copy.isAlive(), false);
}
TEST(LifeFixture, cell_cpy_constr_3) {
  FredkinCell fc = FredkinCell(true);
  Cell c = Cell(&fc);
  Cell copy = c;
  ASSERT_EQ(copy.isAlive(), true);
}
TEST(LifeFixture, cell_cpy_constr_4) {
  ConwayCell cc = ConwayCell(true);
  Cell c = Cell(&cc);
  Cell copy = c;
  ASSERT_EQ(copy.isAlive(), true);
}
TEST(LifeFixture, cell_cpy_constr_5) {
  FredkinCell fc = FredkinCell(false);
  Cell c = Cell(&fc);
  Cell copy = c;
  ASSERT_EQ(copy.isAlive(), c.isAlive());
}
TEST(LifeFixture, cell_cpy_constr_6) {
  ConwayCell cc = ConwayCell(false);
  Cell c = Cell(&cc);
  Cell copy = c;
  ASSERT_EQ(copy.isAlive(), c.isAlive());
}
TEST(LifeFixture, cell_cpy_constr_7) {
  FredkinCell fc = FredkinCell(true);
  Cell c = Cell(&fc);
  Cell copy = c;
  ASSERT_EQ(copy.isAlive(), c.isAlive());
}
TEST(LifeFixture, cell_cpy_constr_8) {
  ConwayCell cc = ConwayCell(true);
  Cell c = Cell(&cc);
  Cell copy = c;
  ASSERT_EQ(copy.isAlive(), c.isAlive());
}
// Cell update
TEST(LifeFixture, cell_update_1) {
  FredkinCell fc = FredkinCell(false);
  Cell c = Cell(&fc);
  c.update(1);
  c.update(1);
  ASSERT_EQ(c.toChar(), '1');
}
TEST(LifeFixture, cell_update_2) {
  FredkinCell fc = FredkinCell(false);
  Cell c = Cell(&fc);
  c.update(2);
  ASSERT_EQ(c.isAlive(), false);
}
TEST(LifeFixture, cell_update_3) {
  FredkinCell fc = FredkinCell(false);
  Cell c = Cell(&fc);
  c.update(2);
  ASSERT_EQ(c.toChar(), '-');
}
TEST(LifeFixture, cell_update_4) {
  FredkinCell fc = FredkinCell(false);
  Cell c = Cell(&fc);
  c.update(1);
  ASSERT_EQ(c.toChar(), '0');
}
TEST(LifeFixture, cell_update_5) {
  Cell c = Cell();
  c.update(1);
  c.update(1);
  ASSERT_EQ(c.toChar(), '.');
}
TEST(LifeFixture, cell_update_6) {
  FredkinCell fc = FredkinCell(true);
  Cell c = Cell(&fc);
  c.update(1);
  c.update(1);
  ASSERT_EQ(c.toChar(), '*');
}
// Cell isNeighbor
TEST(LifeFixture, cell_is_neighbor_1) {
  FredkinCell fc = FredkinCell();
  Cell c = Cell(&fc);
  const bool b = c.isNeighbor(1);
  ASSERT_EQ(b, true);
}
TEST(LifeFixture, cell_is_neighbor_2) {
  FredkinCell fc = FredkinCell();
  Cell c = Cell(&fc);
  const bool b = c.isNeighbor(2);
  ASSERT_EQ(b, false);
}
TEST(LifeFixture, cell_is_neighbor_3) {
  Cell c = Cell();
  const bool b = c.isNeighbor(3);
  ASSERT_EQ(b, true);
}
TEST(LifeFixture, cell_is_neighbor_4) {
  Cell c = Cell();
  const bool b = c.isNeighbor(2);
  ASSERT_EQ(b, true);
}

// Cell toChar
TEST(LifeFixture, cell_to_char_1) {
  FredkinCell fc = FredkinCell(true);
  Cell c = Cell(&fc);
  ASSERT_EQ(c.toChar(), '0');
}
TEST(LifeFixture, cell_to_char_2) {
  Cell c = Cell();
  c.update(1);
  ASSERT_EQ(c.toChar(), '.');
}
TEST(LifeFixture, cell_to_char_3) {
  FredkinCell fc = FredkinCell(false);
  Cell c = Cell(&fc);
  ASSERT_EQ(c.toChar(), '-');
}
TEST(LifeFixture, cell_is_alive_1) {
  FredkinCell fc = FredkinCell(true);
  Cell c = Cell(&fc);
  ASSERT_EQ(c.isAlive(), true);
}
TEST(LifeFixture, cell_is_alive_2) {
  Cell c = Cell();
  ASSERT_EQ(c.isAlive(), false);
}
//
/////////// Life Tests
TEST(LifeFixture, life_constructor_1) {
  Life<int> a = Life<int>(2, 3);
  ASSERT_EQ(a.grid.size(), 3);
}
TEST(LifeFixture, life_constructor_2) {
  Life<int> a = Life<int>(2, 3);
  ASSERT_EQ(a.grid[0].size(), 2);
}
TEST(LifeFixture, life_constructor_3) {
  Life<int> a = Life<int>(5, 1);
  ASSERT_EQ(a._w, 5);
}
TEST(LifeFixture, life_constructor_4) {
  Life<int> a = Life<int>(5, 1);
  ASSERT_EQ(a._h, 1);
}
TEST(LifeFixture, life_constructor_5) {
  Life<int> a = Life<int>(1, 1);
  ASSERT_EQ(a.age, 0);
}

// Life evolve
TEST(LifeFixture, life_evolve_1) {
  Life<FredkinCell> a = Life<FredkinCell>(3, 3);
  FredkinCell f = FredkinCell(true);
  a.insertCell(f, 0, 0);
  a.insertCell(f, 2, 0);
  a.insertCell(f, 1, 1);
  a.insertCell(f, 2, 1);
  a.insertCell(f, 1, 2);
  a.insertCell(f, 2, 2);
  a.evolve();
  ASSERT_TRUE(a.grid[0][1].isAlive());
}
TEST(LifeFixture, life_evolve_2) {
  Life<FredkinCell> a = Life<FredkinCell>(3, 3);
  FredkinCell f = FredkinCell(true);
  a.insertCell(f, 0, 0);
  a.insertCell(f, 2, 0);
  a.insertCell(f, 1, 1);
  a.insertCell(f, 2, 1);
  a.insertCell(f, 1, 2);
  a.insertCell(f, 2, 2);
  a.evolve();
  ASSERT_TRUE(a.grid[0][2].isAlive());
}
TEST(LifeFixture, life_evolve_3) {
  Life<FredkinCell> a = Life<FredkinCell>(3, 3);
  FredkinCell f = FredkinCell(true);
  a.insertCell(f, 0, 0);
  a.insertCell(f, 2, 0);
  a.insertCell(f, 1, 1);
  a.insertCell(f, 2, 1);
  a.insertCell(f, 1, 2);
  a.insertCell(f, 2, 2);
  a.evolve();
  ASSERT_TRUE(a.grid[1][2].isAlive());
}
TEST(LifeFixture, life_evolve_4) {
  Life<FredkinCell> a = Life<FredkinCell>(3, 3);
  FredkinCell f = FredkinCell(true);
  a.insertCell(f, 0, 0);
  a.insertCell(f, 2, 0);
  a.insertCell(f, 1, 1);
  a.insertCell(f, 2, 1);
  a.insertCell(f, 1, 2);
  a.insertCell(f, 2, 2);
  a.evolve();
  ASSERT_TRUE(a.grid[2][0].isAlive());
}
TEST(LifeFixture, life_evolve_5) {
  Life<FredkinCell> a = Life<FredkinCell>(3, 3);
  FredkinCell f = FredkinCell(true);
  a.insertCell(f, 0, 0);
  a.insertCell(f, 2, 0);
  a.insertCell(f, 1, 1);
  a.insertCell(f, 2, 1);
  a.insertCell(f, 1, 2);
  a.insertCell(f, 2, 2);
  a.evolve();
  ASSERT_FALSE(a.grid[0][0].isAlive());
}
TEST(LifeFixture, life_evolve_6) {
  Life<FredkinCell> a = Life<FredkinCell>(3, 3);
  FredkinCell f = FredkinCell(true);
  a.insertCell(f, 0, 0);
  a.insertCell(f, 2, 0);
  a.insertCell(f, 1, 1);
  a.insertCell(f, 2, 1);
  a.insertCell(f, 1, 2);
  a.insertCell(f, 2, 2);
  a.evolve();
  ASSERT_FALSE(a.grid[1][0].isAlive());
}
TEST(LifeFixture, life_evolve_7) {
  Life<FredkinCell> a = Life<FredkinCell>(3, 3);
  FredkinCell f = FredkinCell(true);
  a.insertCell(f, 0, 0);
  a.insertCell(f, 2, 0);
  a.insertCell(f, 1, 1);
  a.insertCell(f, 2, 1);
  a.insertCell(f, 1, 2);
  a.insertCell(f, 2, 2);
  a.evolve();
  ASSERT_FALSE(a.grid[1][1].isAlive());
}
TEST(LifeFixture, life_evolve_8) {
  Life<FredkinCell> a = Life<FredkinCell>(3, 3);
  FredkinCell f = FredkinCell(true);
  a.insertCell(f, 0, 0);
  a.insertCell(f, 2, 0);
  a.insertCell(f, 1, 1);
  a.insertCell(f, 2, 1);
  a.insertCell(f, 1, 2);
  a.insertCell(f, 2, 2);
  a.evolve();
  ASSERT_FALSE(a.grid[2][1].isAlive());
}
TEST(LifeFixture, life_evolve_9) {
  Life<FredkinCell> a = Life<FredkinCell>(3, 3);
  FredkinCell f = FredkinCell(true);
  a.insertCell(f, 0, 0);
  a.insertCell(f, 2, 0);
  a.insertCell(f, 1, 1);
  a.insertCell(f, 2, 1);
  a.insertCell(f, 1, 2);
  a.insertCell(f, 2, 2);
  a.evolve();
  ASSERT_FALSE(a.grid[2][2].isAlive());
}
TEST(LifeFixture, life_evolve_10) {
  Life<ConwayCell> a = Life<ConwayCell>(3, 3);
  ConwayCell c = ConwayCell(true);
  a.insertCell(c, 0, 0);
  a.insertCell(c, 2, 0);
  a.insertCell(c, 1, 1);
  a.insertCell(c, 2, 1);
  a.insertCell(c, 1, 2);
  a.insertCell(c, 2, 2);
  a.evolve();
  ASSERT_TRUE(a.grid[0][2].isAlive());
}
TEST(LifeFixture, life_evolve_11) {
  Life<ConwayCell> a = Life<ConwayCell>(3, 3);
  ConwayCell c = ConwayCell(true);
  a.insertCell(c, 0, 0);
  a.insertCell(c, 2, 0);
  a.insertCell(c, 1, 1);
  a.insertCell(c, 2, 1);
  a.insertCell(c, 1, 2);
  a.insertCell(c, 2, 2);
  a.evolve();
  ASSERT_TRUE(a.grid[1][0].isAlive());
}
TEST(LifeFixture, life_evolve_12) {
  Life<ConwayCell> a = Life<ConwayCell>(3, 3);
  ConwayCell c = ConwayCell(true);
  a.insertCell(c, 0, 0);
  a.insertCell(c, 2, 0);
  a.insertCell(c, 1, 1);
  a.insertCell(c, 2, 1);
  a.insertCell(c, 1, 2);
  a.insertCell(c, 2, 2);
  a.evolve();
  ASSERT_TRUE(a.grid[2][1].isAlive());
}
TEST(LifeFixture, life_evolve_13) {
  Life<ConwayCell> a = Life<ConwayCell>(3, 3);
  ConwayCell c = ConwayCell(true);
  a.insertCell(c, 0, 0);
  a.insertCell(c, 2, 0);
  a.insertCell(c, 1, 1);
  a.insertCell(c, 2, 1);
  a.insertCell(c, 1, 2);
  a.insertCell(c, 2, 2);
  a.evolve();
  ASSERT_TRUE(a.grid[2][2].isAlive());
}
TEST(LifeFixture, life_evolve_14) {
  Life<ConwayCell> a = Life<ConwayCell>(3, 3);
  ConwayCell c = ConwayCell(true);
  a.insertCell(c, 0, 0);
  a.insertCell(c, 2, 0);
  a.insertCell(c, 1, 1);
  a.insertCell(c, 2, 1);
  a.insertCell(c, 1, 2);
  a.insertCell(c, 2, 2);
  a.evolve();
  ASSERT_FALSE(a.grid[0][0].isAlive());
}
TEST(LifeFixture, life_evolve_15) {
  Life<ConwayCell> a = Life<ConwayCell>(3, 3);
  ConwayCell c = ConwayCell(true);
  a.insertCell(c, 0, 0);
  a.insertCell(c, 2, 0);
  a.insertCell(c, 1, 1);
  a.insertCell(c, 2, 1);
  a.insertCell(c, 1, 2);
  a.insertCell(c, 2, 2);
  a.evolve();
  ASSERT_FALSE(a.grid[0][1].isAlive());
}
TEST(LifeFixture, life_evolve_16) {
  Life<ConwayCell> a = Life<ConwayCell>(3, 3);
  ConwayCell c = ConwayCell(true);
  a.insertCell(c, 0, 0);
  a.insertCell(c, 2, 0);
  a.insertCell(c, 1, 1);
  a.insertCell(c, 2, 1);
  a.insertCell(c, 1, 2);
  a.insertCell(c, 2, 2);
  a.evolve();
  ASSERT_FALSE(a.grid[1][1].isAlive());
}
TEST(LifeFixture, life_evolve_17) {
  Life<ConwayCell> a = Life<ConwayCell>(3, 3);
  ConwayCell c = ConwayCell(true);
  a.insertCell(c, 0, 0);
  a.insertCell(c, 2, 0);
  a.insertCell(c, 1, 1);
  a.insertCell(c, 2, 1);
  a.insertCell(c, 1, 2);
  a.insertCell(c, 2, 2);
  a.evolve();
  ASSERT_FALSE(a.grid[1][2].isAlive());
}
TEST(LifeFixture, life_evolve_18) {
  Life<ConwayCell> a = Life<ConwayCell>(3, 3);
  ConwayCell c = ConwayCell(true);
  a.insertCell(c, 0, 0);
  a.insertCell(c, 2, 0);
  a.insertCell(c, 1, 1);
  a.insertCell(c, 2, 1);
  a.insertCell(c, 1, 2);
  a.insertCell(c, 2, 2);
  a.evolve();
  ASSERT_FALSE(a.grid[2][0].isAlive());
}