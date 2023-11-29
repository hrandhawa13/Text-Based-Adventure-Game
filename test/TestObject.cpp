#include "Object.h"

#include "gtest/gtest.h"

TEST(TestObject, constructorTest) {
  std::string name = "name";
  std::string description = "description";
  Object obj(name, description);
  EXPECT_EQ(obj.getName(), name);
  EXPECT_EQ(obj.getDescription(), description);
}

TEST(TestObject, lookTest) {
  std::string name = "name";
  std::string description = "description";
  Object obj(name, description);
  EXPECT_EQ(obj.look(), "You are looking at " + name);
}

TEST(TestObject, touchTest) {
  std::string name = "name";
  std::string description = "description";
  Object obj(name, description);
  EXPECT_EQ(obj.touch(), "You touched " + name);
}

TEST(TestObject, examineTest) {
  std::string name = "name";
  std::string description = "description";
  Object obj(name, description);
  EXPECT_EQ(obj.examine(), "Examining " + name +":" + description);
}

TEST(TestObject, throwObjectTest) {
  std::string name = "name";
  std::string description = "description";
  Object obj(name, description);
  EXPECT_EQ(obj.throwObject(), "Throwing object :" + name);
}
