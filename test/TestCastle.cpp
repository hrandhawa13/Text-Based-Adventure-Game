#include "Castle.h"
#include "Environment.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class MockInput : public std::streambuf{
 public:
        explicit MockInput(const std::string& input) : input_(input) {}
        friend std:: istream& operator >>
    (std::istream& is, const MockInput& uInput) {
                for (char c : uInput.input_) {
                    is.putback(c);
                }
                return is;
            }
 private:
        std::string input_;
};

TEST(TestCastle, constructorTest) {
    Castle castle;
    EXPECT_EQ(castle.messenger->getName(), "Messenger");
    EXPECT_EQ(castle.key->getName(), "Key");
    EXPECT_EQ(castle.advisor->getName(), "Advisor");
    EXPECT_EQ(castle.sword->getName(), "Sword");
    EXPECT_EQ(castle.armor->getName(), "Armor");
    castle.cleanUp();
    castle.endLevel();
    delete castle.king;
}

TEST(TestCastle, printCurrentLocationTest) {
    Castle castle;
    EXPECT_EQ(castle.king->getLocation(), 0);
    for ( int i = 0; i < 9; i++ ) {
        castle.king->forward();
        castle.printCurrentLocation();
    }
    EXPECT_EQ(castle.king->getLocation(), 8);
    castle.cleanUp();
    castle.endLevel();
    delete castle.king;
}
TEST(TestCastle, printCurrentLocationStageNotCompletedTest) {
    Castle castle;
    castle.stageCompleted = false;
    EXPECT_EQ(castle.king->getLocation(), 0);
    for ( int i = 0; i < 9; i++ ) {
        castle.king->forward();
        castle.printCurrentLocation();
    }
    EXPECT_EQ(castle.king->getLocation(), 8);
    castle.cleanUp();
    castle.endLevel();
    delete castle.king;
}
TEST(TestCastle, generalInputsExitTest) {
    Castle castle;
    castle.stageCompleted = false;
    EXPECT_EQ(castle.king->getHp(), 100);
    castle.generalInputs("exit");
    EXPECT_EQ(castle.king->getHp(), 0);
    castle.cleanUp();
    castle.endLevel();
    delete castle.king;
}
TEST(TestCastle, generalInputsHelpTest) {
    Castle castle;
    castle.stageCompleted = false;
    EXPECT_EQ(castle.king->getHp(), 100);
    castle.generalInputs("help");
    EXPECT_EQ(castle.king->getHp(), 100);
    castle.cleanUp();
    castle.endLevel();
    delete castle.king;
}
TEST(TestCastle, generalInputsPrintTest) {
    Castle castle;
    castle.stageCompleted = false;
    EXPECT_EQ(castle.king->getHp(), 100);
    castle.generalInputs("print");
    EXPECT_EQ(castle.king->getHp(), 100);
    castle.cleanUp();
    castle.endLevel();
    delete castle.king;
}
TEST(TestCastle, generalInputsStatusTest) {
    Castle castle;
    castle.stageCompleted = false;
    EXPECT_EQ(castle.king->getHp(), 100);
    castle.generalInputs("status");
    EXPECT_EQ(castle.king->getHp(), 100);
    castle.cleanUp();
    castle.endLevel();
    delete castle.king;
}
TEST(TestCastle, generalInputsUnknownTest) {
    Castle castle;
    castle.stageCompleted = false;
    EXPECT_EQ(castle.king->getHp(), 100);
    castle.generalInputs("unknown");
    EXPECT_EQ(castle.king->getHp(), 100);
    castle.cleanUp();
    castle.endLevel();
    delete castle.king;
}
