#include "gtest/gtest.h"
#include "TextBuffer.h"

class DoublyLinkedListTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup before each test
    }

    void TearDown() override {
        // Cleanup after each test
    }
};

// Test multiple data types with templates
template<typename T>
class TypedDLLTest : public ::testing::Test {};

typedef ::testing::Types<int, char, double, std::string> DataTypes;
TYPED_TEST_SUITE(TypedDLLTest, DataTypes);

// ===== CONSTRUCTOR & DESTRUCTOR TESTS =====
TEST_F(DoublyLinkedListTest, EmptyConstructor) {
    DoublyLinkedList<int> dll;
    EXPECT_EQ(dll.size(), 0);
    EXPECT_EQ(dll.toString(), "[]");
}

TEST_F(DoublyLinkedListTest, DestructorEmptyList) {
    { // Scope for destructor call
        DoublyLinkedList<int> dll;
    } // Destructor should not crash
    SUCCEED();
}

TEST_F(DoublyLinkedListTest, DestructorNonEmptyList) {
    {
        DoublyLinkedList<int> dll;
        dll.insertAtTail(1);
        dll.insertAtTail(2);
    } // Should free memory without leaks
    SUCCEED();
}

// ===== INSERT AT HEAD TESTS =====
TYPED_TEST(TypedDLLTest, InsertAtHeadEmptyList) {
    DoublyLinkedList<TypeParam> dll;
    dll.insertAtHead(TypeParam());
    EXPECT_EQ(dll.size(), 1);
}

TYPED_TEST(TypedDLLTest, InsertAtHeadMultipleItems) {
    DoublyLinkedList<TypeParam> dll;
    dll.insertAtHead(TypeParam());
    dll.insertAtHead(TypeParam());
    EXPECT_EQ(dll.size(), 2);
}

TEST_F(DoublyLinkedListTest, InsertAtHeadInt) {
    DoublyLinkedList<int> dll;
    dll.insertAtHead(5);
    dll.insertAtHead(10);
    EXPECT_EQ(dll.toString(), "[10, 5]");
}

TEST_F(DoublyLinkedListTest, InsertAtHeadString) {
    DoublyLinkedList<std::string> dll;
    dll.insertAtHead("world");
    dll.insertAtHead("hello");
    EXPECT_EQ(dll.toString(), "[hello, world]");
}

// ===== INSERT AT TAIL TESTS =====
TYPED_TEST(TypedDLLTest, InsertAtTailEmptyList) {
    DoublyLinkedList<TypeParam> dll;
    dll.insertAtTail(TypeParam());
    EXPECT_EQ(dll.size(), 1);
}

TYPED_TEST(TypedDLLTest, InsertAtTailMultipleItems) {
    DoublyLinkedList<TypeParam> dll;
    dll.insertAtTail(TypeParam());
    dll.insertAtTail(TypeParam());
    EXPECT_EQ(dll.size(), 2);
}

TEST_F(DoublyLinkedListTest, InsertAtTailInt) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    EXPECT_EQ(dll.toString(), "[1, 2]");
}

// ===== INSERT AT INDEX TESTS =====
TEST_F(DoublyLinkedListTest, InsertAtZeroEmptyList) {
    DoublyLinkedList<int> dll;
    dll.insertAt(0, 100);
    EXPECT_EQ(dll.toString(), "[100]");
}

TEST_F(DoublyLinkedListTest, InsertAtBeginning) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(2);
    dll.insertAt(0, 1);
    EXPECT_EQ(dll.toString(), "[1, 2]");
}

TEST_F(DoublyLinkedListTest, InsertAtEnd) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    dll.insertAt(1, 2);
    EXPECT_EQ(dll.toString(), "[1, 2]");
}

TEST_F(DoublyLinkedListTest, InsertAtMiddle) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    dll.insertAtTail(3);
    dll.insertAt(1, 2);
    EXPECT_EQ(dll.toString(), "[1, 2, 3]");
}

TEST_F(DoublyLinkedListTest, InsertAtNegativeIndex) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    EXPECT_THROW(dll.insertAt(-1, 0), std::out_of_range);
}

TEST_F(DoublyLinkedListTest, InsertAtIndexGreaterThanSize) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    EXPECT_THROW(dll.insertAt(2, 0), std::out_of_range);
}

TEST_F(DoublyLinkedListTest, InsertAtSizeBoundary) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    dll.insertAt(1, 2); // Should work
    EXPECT_EQ(dll.toString(), "[1, 2]");
}

// ===== DELETE AT TESTS =====
TEST_F(DoublyLinkedListTest, DeleteAtEmptyList) {
    DoublyLinkedList<int> dll;
    EXPECT_THROW(dll.deleteAt(0), std::out_of_range);
}

TEST_F(DoublyLinkedListTest, DeleteAtNegativeIndex) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    EXPECT_THROW(dll.deleteAt(-1), std::out_of_range);
}

TEST_F(DoublyLinkedListTest, DeleteAtIndexGreaterThanSize) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    EXPECT_THROW(dll.deleteAt(1), std::out_of_range);
}

TEST_F(DoublyLinkedListTest, DeleteAtOnlyElement) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    dll.deleteAt(0);
    EXPECT_EQ(dll.size(), 0);
    EXPECT_EQ(dll.toString(), "[]");
}

TEST_F(DoublyLinkedListTest, DeleteAtBeginning) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.deleteAt(0);
    EXPECT_EQ(dll.toString(), "[2]");
}

TEST_F(DoublyLinkedListTest, DeleteAtEnd) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.deleteAt(1);
    EXPECT_EQ(dll.toString(), "[1]");
}

TEST_F(DoublyLinkedListTest, DeleteAtMiddle) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.insertAtTail(3);
    dll.deleteAt(1);
    EXPECT_EQ(dll.toString(), "[1, 3]");
}

// ===== GET TESTS =====
TEST_F(DoublyLinkedListTest, GetEmptyList) {
    DoublyLinkedList<int> dll;
    EXPECT_THROW(dll.get(0), std::out_of_range);
}

TEST_F(DoublyLinkedListTest, GetNegativeIndex) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    EXPECT_THROW(dll.get(-1), std::out_of_range);
}

TEST_F(DoublyLinkedListTest, GetOutOfBounds) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    EXPECT_THROW(dll.get(1), std::out_of_range);
}

TEST_F(DoublyLinkedListTest, GetValidIndex) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(42);
    EXPECT_EQ(dll.get(0), 42);
}

TEST_F(DoublyLinkedListTest, GetMultipleItems) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(10);
    dll.insertAtTail(20);
    dll.insertAtTail(30);
    EXPECT_EQ(dll.get(1), 20);
}

// ===== INDEXOF TESTS =====
TEST_F(DoublyLinkedListTest, IndexOfEmptyList) {
    DoublyLinkedList<int> dll;
    EXPECT_EQ(dll.indexOf(1), -1);
}

TEST_F(DoublyLinkedListTest, IndexOfNotFound) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    EXPECT_EQ(dll.indexOf(2), -1);
}

TEST_F(DoublyLinkedListTest, IndexOfFound) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    EXPECT_EQ(dll.indexOf(2), 1);
}

TEST_F(DoublyLinkedListTest, IndexOfFirstOccurrence) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.insertAtTail(1);
    EXPECT_EQ(dll.indexOf(1), 0);
}

// ===== CONTAINS TESTS =====
TEST_F(DoublyLinkedListTest, ContainsEmptyList) {
    DoublyLinkedList<int> dll;
    EXPECT_FALSE(dll.contains(1));
}

TEST_F(DoublyLinkedListTest, ContainsNotFound) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    EXPECT_FALSE(dll.contains(2));
}

TEST_F(DoublyLinkedListTest, ContainsFound) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    EXPECT_TRUE(dll.contains(1));
}

// ===== SIZE TESTS =====
TEST_F(DoublyLinkedListTest, SizeEmpty) {
    DoublyLinkedList<int> dll;
    EXPECT_EQ(dll.size(), 0);
}

TEST_F(DoublyLinkedListTest, SizeAfterInsert) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    EXPECT_EQ(dll.size(), 2);
}

TEST_F(DoublyLinkedListTest, SizeAfterDelete) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.deleteAt(0);
    EXPECT_EQ(dll.size(), 1);
}

// ===== REVERSE TESTS =====
TEST_F(DoublyLinkedListTest, ReverseEmptyList) {
    DoublyLinkedList<int> dll;
    dll.reverse();
    EXPECT_EQ(dll.toString(), "[]");
}

TEST_F(DoublyLinkedListTest, ReverseSingleElement) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    dll.reverse();
    EXPECT_EQ(dll.toString(), "[1]");
}

TEST_F(DoublyLinkedListTest, ReverseMultipleElements) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.insertAtTail(3);
    dll.reverse();
    EXPECT_EQ(dll.toString(), "[3, 2, 1]");
}

TEST_F(DoublyLinkedListTest, ReverseTwice) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.insertAtTail(3);
    dll.reverse();
    dll.reverse();
    EXPECT_EQ(dll.toString(), "[1, 2, 3]");
}

// ===== TOSTRING TESTS =====
TEST_F(DoublyLinkedListTest, ToStringEmpty) {
    DoublyLinkedList<int> dll;
    EXPECT_EQ(dll.toString(), "[]");
}

TEST_F(DoublyLinkedListTest, ToStringSingle) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(42);
    EXPECT_EQ(dll.toString(), "[42]");
}

TEST_F(DoublyLinkedListTest, ToStringMultiple) {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.insertAtTail(3);
    EXPECT_EQ(dll.toString(), "[1, 2, 3]");
}

TEST_F(DoublyLinkedListTest, ToStringWithStrings) {
    DoublyLinkedList<std::string> dll;
    dll.insertAtTail("hello");
    dll.insertAtTail("world");
    EXPECT_EQ(dll.toString(), "[hello, world]");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}