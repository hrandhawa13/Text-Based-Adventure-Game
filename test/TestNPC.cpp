#include "NPC.h"

#include "gtest/gtest.h"

TEST(TestNPC, constructorTest) {
  NPC npcMessenger("Messenger");
  NPC npcAdvisor("Advisor");
  NPC npcIncorrect("Leader");
  EXPECT_EQ(npcMessenger.getName(), "Messenger");
  EXPECT_EQ(npcAdvisor.getName(), "Advisor");
  EXPECT_EQ(npcIncorrect.getName(), "Leader");
}

TEST(TestNPC, getDialogueTest) {
  NPC npcMessenger("Messenger");
  NPC npcAdvisor("Advisor");
  NPC npcIncorrect("Leader");
  EXPECT_EQ(npcMessenger.getDialogue(), "Princess has been kidnapped");
  EXPECT_EQ(npcAdvisor.getDialogue(),
   "Be careful, this adventure is risky. Would you like to exit?");
  EXPECT_EQ(npcIncorrect.getDialogue(), "No Dialogues available");
}
