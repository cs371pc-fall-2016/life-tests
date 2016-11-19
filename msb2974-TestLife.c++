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

// ----
// test
// ----

TEST(LifeFixture, Conway1) {
  ostringstream w;

  ConwayCell c('.');

  w << c;

  ASSERT_EQ(".", w.str());
}

TEST(LifeFixture, Conway2) {
  ostringstream w;

  ConwayCell c('*');

  w << c;

  ASSERT_EQ("*", w.str());
}

TEST(LifeFixture, Conway3) {
  ConwayCell c('*');
  ASSERT_TRUE(c.is_alive());
}

TEST(LifeFixture, Conway4) {
  ConwayCell c('.');
  ASSERT_FALSE(c.is_alive());
}

TEST(LifeFixture, Conway5) {
  ConwayCell c('.');
  ASSERT_FALSE(c.is_neighbor(0, 0));
}

TEST(LifeFixture, Conway6) {
  ConwayCell c('.');
  ASSERT_TRUE(c.is_neighbor(0, 1));
}

TEST(LifeFixture, Conway7) {
  ConwayCell c('.');
  ASSERT_TRUE(c.is_neighbor(-1, 1));
}

TEST(LifeFixture, Conway8) {
  ostringstream w;

  ConwayCell c('.');
  c.evolve(3);
  w << c;

  ASSERT_EQ("*", w.str());
}

TEST(LifeFixture, Conway9) {
  ostringstream w;

  ConwayCell c('.');
  c.evolve(1);
  w << c;

  ASSERT_EQ(".", w.str());
}

TEST(LifeFixture, Conway10) {
  ostringstream w;

  ConwayCell c('*');
  c.evolve(3);
  w << c;

  ASSERT_EQ("*", w.str());
}

TEST(LifeFixture, Conway11) {
  ostringstream w;

  ConwayCell c('*');
  c.evolve(1);
  w << c;

  ASSERT_EQ(".", w.str());
}

TEST(LifeFixture, Fredkin1) { ASSERT_FALSE(FredkinCell('-').is_alive()); }

TEST(LifeFixture, Fredkin2) { ASSERT_TRUE(FredkinCell('0').is_alive()); }

TEST(LifeFixture, Fredkin3) { ASSERT_TRUE(FredkinCell('+').is_alive()); }

TEST(LifeFixture, Fredkin4) {
  FredkinCell f('-');
  f.evolve(1);

  ASSERT_TRUE(f.is_alive());
}

TEST(LifeFixture, Fredkin5) {
  FredkinCell f('-');
  f.evolve(2);

  ASSERT_FALSE(f.is_alive());
}

TEST(LifeFixture, Fredkin6) {
  FredkinCell f('0');
  f.evolve(2);

  ASSERT_FALSE(f.is_alive());
}

TEST(LifeFixture, Fredkin7) {
  ostringstream w;

  FredkinCell f('0');
  f.evolve(3);
  w << f;

  ASSERT_EQ("1", w.str());
}

TEST(LifeFixture, Fredkin8) {
  ostringstream w;

  FredkinCell f('0');

  for (int i = 0; i < 10; i++)
    f.evolve(3);
  w << f;

  ASSERT_EQ("+", w.str());
}

TEST(LifeFixture, Fredkin9) {
  FredkinCell f('0');

  f.evolve(3);
  f.evolve(3);

  ASSERT_TRUE(f.is_2());
}

TEST(LifeFixture, Fredkin10) {
  FredkinCell f('0');

  f.evolve(3);
  f.evolve(3);
  f.evolve(3);

  ASSERT_FALSE(f.is_2());
}

TEST(LifeFixture, Fredkin11) {
  ASSERT_TRUE(FredkinCell('0').is_neighbor(0, 1));
}

TEST(LifeFixture, Fredkin12) {
  ASSERT_FALSE(FredkinCell('0').is_neighbor(0, 0));
}

TEST(LifeFixture, Fredkin13) {
  ASSERT_FALSE(FredkinCell('0').is_neighbor(1, -1));
}

TEST(LifeFixture, Cell1) {
  ostringstream w;

  Cell c(new ConwayCell('.'));

  w << c;

  ASSERT_EQ(".", w.str());
}

TEST(LifeFixture, Cell2) {
  ostringstream w;

  Cell c(new ConwayCell('*'));

  w << c;

  ASSERT_EQ("*", w.str());
}

TEST(LifeFixture, Cell3) {
  ostringstream w;

  Cell c(new FredkinCell('0'));

  w << c;

  ASSERT_EQ("0", w.str());
}

TEST(LifeFixture, Cell4) {
  ostringstream w;

  Cell c(new FredkinCell('-'));

  w << c;

  ASSERT_EQ("-", w.str());
}

TEST(LifeFixture, Cell5) {
  Cell c(new FredkinCell('-'));
  ASSERT_FALSE(c.is_alive());
}

TEST(LifeFixture, Cell6) {
  Cell c(new ConwayCell('*'));
  ASSERT_TRUE(c.is_alive());
}

TEST(LifeFixture, Cell7) {
  Cell c(new ConwayCell('*'));
  c.evolve(1);
  ASSERT_FALSE(c.is_alive());
}

TEST(LifeFixture, Cell8) {
  Cell c(new ConwayCell('*'));
  c.evolve(3);
  ASSERT_TRUE(c.is_alive());
}

TEST(LifeFixture, Cell9) {
  Cell c(new FredkinCell('-'));
  c.evolve(1);
  ASSERT_TRUE(c.is_alive());
}

TEST(LifeFixture, Cell10) {
  Cell c(new FredkinCell('-'));
  c.evolve(2);
  ASSERT_FALSE(c.is_alive());
}

TEST(LifeFixture, Cell11) {
  ostringstream w;

  Cell c(new FredkinCell('0'));

  for (int i = 0; i < 10; i++) {
    c.evolve(3);
  }

  w << c;

  ASSERT_EQ("*", w.str());
}

TEST(LifeFixture, Cell12) {
  ostringstream w;

  Cell c(new FredkinCell('0'));

  for (int i = 0; i < 10; i++) {
    c.evolve(2);
  }

  w << c;

  ASSERT_EQ("-", w.str());
}

TEST(LifeFixture, Life1) {
  ostringstream w;

  Life<ConwayCell> b(1, 1);

  b.addCell(0, 0, ConwayCell('.'));
  b.endTurn();

  w << b;

  ASSERT_EQ("Generation = 0, Population = 0.\n.\n", w.str());
}

TEST(LifeFixture, Life2) {
  ostringstream w;

  Life<ConwayCell> b(1, 1);

  b.addCell(0, 0, ConwayCell('*'));
  b.endTurn();

  w << b;

  ASSERT_EQ("Generation = 0, Population = 1.\n*\n", w.str());
}

TEST(LifeFixture, Life3) {
  ostringstream w;

  Life<ConwayCell> b(1, 1);

  b.addCell(0, 0, ConwayCell('*'));
  b.endTurn();
  ++b;

  w << b;

  ASSERT_EQ("Generation = 1, Population = 0.\n.\n", w.str());
}

TEST(LifeFixture, Life4) {
  ostringstream w;

  Life<FredkinCell> b(1, 1);

  b.addCell(0, 0, FredkinCell('0'));
  b.endTurn();
  ++b;

  w << b;

  ASSERT_EQ("Generation = 1, Population = 0.\n-\n", w.str());
}

TEST(LifeFixture, Life5) {
  ostringstream w;

  Life<FredkinCell> b(1, 2);

  b.addCell(0, 0, FredkinCell('0'));
  b.addCell(0, 1, FredkinCell('0'));

  b.endTurn();
  ++b;

  w << b;

  ASSERT_EQ("Generation = 1, Population = 2.\n11\n", w.str());
}

TEST(LifeFixture, Life6) {
  ostringstream w;

  Life<FredkinCell> b(1, 2);

  b.addCell(0, 0, FredkinCell('0'));
  b.addCell(0, 1, FredkinCell('-'));

  b.endTurn();
  ++b;

  w << b;

  ASSERT_EQ("Generation = 1, Population = 1.\n-0\n", w.str());
}

TEST(LifeFixture, Life7) {
  ostringstream w;

  Life<FredkinCell> b(1, 3);

  b.addCell(0, 0, FredkinCell('0'));
  b.addCell(0, 1, FredkinCell('-'));
  b.addCell(0, 2, FredkinCell('0'));

  b.endTurn();
  ++b;

  w << b;

  ASSERT_EQ("Generation = 1, Population = 0.\n---\n", w.str());
}

TEST(LifeFixture, Life8) {
  ostringstream w;

  Life<Cell> b(1, 3);

  b.addCell(0, 0, Cell(new FredkinCell('0')));
  b.addCell(0, 1, Cell(new ConwayCell('*')));
  b.addCell(0, 2, Cell(new FredkinCell('0')));
  b.endTurn();

  ++b;

  w << b;

  ASSERT_EQ("Generation = 1, Population = 3.\n1*1\n", w.str());
}

TEST(LifeFixture, Life9) {
  ostringstream w;

  Life<Cell> b(1, 3);

  b.addCell(0, 0, Cell(new FredkinCell('0')));
  b.addCell(0, 1, Cell(new ConwayCell('*')));
  b.addCell(0, 2, Cell(new ConwayCell('*')));
  b.endTurn();

  ++b;

  w << b;

  ASSERT_EQ("Generation = 1, Population = 2.\n1*.\n", w.str());
}