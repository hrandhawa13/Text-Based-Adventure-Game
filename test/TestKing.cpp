#include <iostream>
#include <string>
#include <vector>
#include "../include/King.h"

#include "gtest/gtest.h"


TEST(TestKing, attackTEST) {
  King king;
  std::string  pass = "You swing your sword at steve";
  EXPECT_EQ(king.attack("steve"), pass);
}
TEST(TestKing, construstorTest) {
  King king("Steve");
  EXPECT_EQ(king.getName(), "Steve");
}

TEST(TestKing, persuadeTEST) {
  King king;
  std::string  pass = "Believe me i am telling the truth.";
  EXPECT_EQ(king.persuade(), pass);
}

TEST(TestKing, forwardTEST) {
  King king;
  std::string  pass = "You moved forward ";
  EXPECT_EQ(king.forward(), pass);
}

TEST(TestKing, runTEST) {
  King king;
  std::string  pass = "You start running ";
  EXPECT_EQ(king.run(), pass);
}

TEST(TestKing, setNameTEST) {
  King king;
  king.setName("steve");
  EXPECT_EQ(king.getName(), "steve");
}

TEST(TestKing, setHpTEST) {
  King king;
  king.setHp(50);
  EXPECT_EQ(king.getHp(), 50);
}

TEST(TestKing, pickupTEST) {
  King king;
  Object object("dagger", "this is a dagger");
  king.pickUpItem(&object);
  EXPECT_EQ(king.getSatchelSize(), 1);
}
TEST(TestKing, hasItemTEST) {
  King king;
  Object object("dagger", "this is a dagger");
  king.pickUpItem(&object);
  king.hasItem("dagger");
  EXPECT_EQ(king.hasItem("dagger"), true);
}
TEST(TestKing, getItemTEST) {
  King king;
  Object object("dagger", "this is a dagger");
  king.pickUpItem(&object);
  EXPECT_EQ(king.getItem("dagger")->getName(), "dagger");
}
TEST(TestKing, putDownTEST) {
  King king;
  Object object("dagger", "this is a dagger");
  king.pickUpItem(&object);
  king.putDownItem(&object);
  EXPECT_EQ(king.getSatchelSize(), 0);
}

TEST(TestKing, putDownInvalidTEST) {
  King king;
  Object object2("sword", "i am a sword");
  Object object("dagger", "this is a dagger");
  king.pickUpItem(&object);
  king.putDownItem(&object2);
  EXPECT_EQ(king.getSatchelSize(), 1);
}

TEST(TestKing, persuadeTest) {
  King king;
  EXPECT_EQ(king.persuade(), "Believe me i am telling the truth.");
}

TEST(TestKing, getLocationTest) {
  King king;
  EXPECT_EQ(king.getLocation(), 0);
  king.forward();
  EXPECT_EQ(king.getLocation(), 1);
}

TEST(TestKing, forwardTest) {
  King king;
  EXPECT_EQ(king.getLocation(), 0);
  EXPECT_EQ(king.forward(), "You moved forward ");
  EXPECT_EQ(king.getLocation(), 1);
}

TEST(TestKing, forwardBlockedTest) {
  King king;
  EXPECT_EQ(king.getLocation(), 0);
  for (int i = 0; i < 9; i++)
    king.forward();
  EXPECT_EQ(king.forward(), "A wall Blocks your path");
  EXPECT_EQ(king.getLocation(), 8);
}
