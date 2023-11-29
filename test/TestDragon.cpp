#include "Dragon.h"

#include "gtest/gtest.h"

TEST(TestDragon, constructorTest) {
  Dragon dragon;
  EXPECT_EQ(dragon.getHealth(), 100);
}

TEST(TestDragon, attackTest) {
  Dragon dragon;
  EXPECT_EQ(dragon.attack(), Dragon::ATTACK_POWER);
  EXPECT_EQ(dragon.getHealth(), 100);
}

TEST(TestDragon, specialAttackTest) {
  Dragon dragon;
  EXPECT_EQ(dragon.specialAttack(), Dragon::SPECIAL_ATTACK_POWER);
  EXPECT_EQ(dragon.getHealth(), 100);
}

TEST(TestDragon, reduceHealth50Test) {
  Dragon dragon;
  dragon.kill(50);
  EXPECT_EQ(dragon.getHealth(), 50);
}

TEST(TestDragon, reduceHealth100Test) {
  Dragon dragon;
  dragon.kill(100);
  EXPECT_EQ(dragon.getHealth(), 0);
}
