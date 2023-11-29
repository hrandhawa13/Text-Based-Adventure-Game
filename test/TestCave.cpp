#include "Cave.h"
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

King *king = new King();
Cave cave(king);

TEST(TestCave, completeLocationOneTest) {
    std::stringstream mockInput("tie");
    std::cin.rdbuf(mockInput.rdbuf());
    std::stringstream output;
    std::streambuf* old1 = std::cout.rdbuf(output.rdbuf());
    cave.completeLocationOne();
    std::cout.rdbuf(old1);
    std::string oo = output.str();
    oo.pop_back();
    oo.erase(0, 1);
    EXPECT_EQ(oo, "You tie up your horse to a nearby tree");
}

TEST(TestCave, completeLocationTwoTest) {
    std::stringstream mockInput("yes");
    std::cin.rdbuf(mockInput.rdbuf());
    std::stringstream output;
    std::streambuf* old1 = std::cout.rdbuf(output.rdbuf());
    cave.completeLocationTwo();
    std::cout.rdbuf(old1);
    std::string oo = output.str();
    oo.pop_back();
    oo.erase(0, 1);
    EXPECT_EQ(oo, "You drink the potion you regained your health");
}

TEST(TestCave, printCurrentLocationTest) {
    EXPECT_EQ(cave.king->getLocation(), 0);
    for ( int i = 0; i < 9; i++ ) {
        cave.king->forward();
        cave.printCurrentLocation();
    }
    EXPECT_EQ(cave.king->getLocation(), 8);
}
TEST(TestCave, generalHelpTest) {
    EXPECT_EQ(cave.king->getHp(), 100);
    cave.generalInputs("help", "help test");
    EXPECT_EQ(cave.king->getHp(), 100);
}

TEST(TestCave, generalUnknownTest) {
    EXPECT_EQ(cave.king->getHp(), 100);
    cave.generalInputs("Unknown", "unknown test");
    EXPECT_EQ(cave.king->getHp(), 100);
}

TEST(TestCave, generalStatusTest) {
    EXPECT_EQ(cave.king->getHp(), 100);
    cave.generalInputs("status", "status test");
    EXPECT_EQ(cave.king->getHp(), 100);
}

TEST(TestCave, generalExitTest) {
    EXPECT_EQ(cave.king->getHp(), 100);
    cave.generalInputs("exit", "exit test");
    EXPECT_EQ(cave.king->getHp(), 100);
    cave.endLevel();
    delete king;
}

