#include "Lion.h"
#include "gtest/gtest.h"

TEST(TestLion, constructorTest) {
  Lion lion;
  EXPECT_EQ(lion.getHealth(), 100);
}

TEST(TestLion, attackTest) {
  Lion lion;
  EXPECT_EQ(lion.attack(), Lion::ATTACK_DMG);
  EXPECT_EQ(lion.getHealth(), 100);
}

TEST(TestLion, specialAttackTest) {
  Lion lion;
  EXPECT_EQ(lion.specialAttack(), Lion::SPECIAL_ATTACK_DMG);
  EXPECT_EQ(lion.getHealth(), 100);
}

TEST(TestLion, reduceHealthTest) {
  Lion lion;
  lion.kill(34);
  EXPECT_EQ(lion.getHealth(), 66);
}

TEST(TestLion, deadTest) {
  Lion lion;
  lion.kill(100);
  EXPECT_EQ(lion.getHealth(), 0);
}
