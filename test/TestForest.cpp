#include "Forest.h"
#include "Environment.h"
#include "gtest/gtest.h"

King *fking = new King();
Forest forest(fking);

TEST(TestForest, printCurrentLocationTest) {
    EXPECT_EQ(forest.king->getLocation(), 0);
    for ( int i = 0; i < 9; i++ ) {
        forest.king->forward();
        forest.printCurrentLocation();
    }
    EXPECT_EQ(forest.king->getLocation(), 8);
}
TEST(TestForest, printCurrentLocationStageNotCompletedTest) {
    forest.stageCompleted = false;
    forest.king->setLocation(0);
    EXPECT_EQ(forest.king->getLocation(), 0);
    for ( int i = 0; i < 9; i++ ) {
        forest.king->forward();
        forest.printCurrentLocation();
    }
    EXPECT_EQ(forest.king->getLocation(), 8);
}
TEST(TestForest, generalInputsExitTest) {
    forest.stageCompleted = false;
    EXPECT_EQ(forest.king->getHp(), 100);
    forest.generalInputs("exit", "exit test");
    EXPECT_EQ(forest.king->getHp(), 0);
}
TEST(TestForest, generalInputsHelpTest) {
    forest.king->heal(100);
    forest.stageCompleted = false;
    EXPECT_EQ(forest.king->getHp(), 100);
    forest.generalInputs("help", "help test");
    EXPECT_EQ(forest.king->getHp(), 100);
}
TEST(TestForest, generalInputsPrintTest) {
    forest.stageCompleted = false;
    EXPECT_EQ(forest.king->getHp(), 100);
    forest.generalInputs("print", "print test");
    EXPECT_EQ(forest.king->getHp(), 100);
}
TEST(TestForest, generalInputsStatusTest) {
    forest.stageCompleted = false;
    EXPECT_EQ(forest.king->getHp(), 100);
    forest.generalInputs("status", "status test");
    EXPECT_EQ(forest.king->getHp(), 100);
}
TEST(TestForest, generalInputsUnknownTest) {
    forest.stageCompleted = false;
    EXPECT_EQ(forest.king->getHp(), 100);
    forest.generalInputs("unknown", "unknown test");
    EXPECT_EQ(forest.king->getHp(), 100);
    forest.endLevel();
    delete fking;
}
