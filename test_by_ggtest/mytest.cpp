#include "gtest/gtest.h"
#include "TextBuffer.h"

using namespace std;

TEST(DoublyLinkedListTest, InsertAtHead) {
    DoublyLinkedList<int> dll;
    dll.insertAtHead(2);
    dll.insertAtHead(1);
    EXPECT_EQ(dll.toString(), "[1, 2]");
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}