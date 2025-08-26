#include "gtest/gtest.h"
#include "TextBuffer.h"

class TextBufferTest : public ::testing::Test {
protected:
    void SetUp() override {
        tb = new TextBuffer();
    }

    void TearDown() override {
        delete tb;
    }

    TextBuffer* tb;
};

// ===== CONSTRUCTOR & DESTRUCTOR TESTS =====
TEST_F(TextBufferTest, Constructor) {
    EXPECT_EQ(tb->getContent(), "");
    EXPECT_EQ(tb->getCursorPos(), 0);
}

TEST_F(TextBufferTest, DestructorEmpty) {
    TextBuffer* localTb = new TextBuffer();
    delete localTb; // Should not crash
    SUCCEED();
}

TEST_F(TextBufferTest, DestructorWithContent) {
    TextBuffer* localTb = new TextBuffer();
    localTb->insert('A');
    delete localTb; // Should free memory
    SUCCEED();
}

// ===== INSERT TESTS =====
TEST_F(TextBufferTest, InsertEmptyBuffer) {
    tb->insert('A');
    EXPECT_EQ(tb->getContent(), "A");
    EXPECT_EQ(tb->getCursorPos(), 1);
}

TEST_F(TextBufferTest, InsertMultipleChars) {
    tb->insert('H');
    tb->insert('i');
    EXPECT_EQ(tb->getContent(), "Hi");
    EXPECT_EQ(tb->getCursorPos(), 2);
}

TEST_F(TextBufferTest, InsertAtCursorPosition) {
    tb->insert('A');
    tb->insert('B');
    tb->moveCursorLeft();
    tb->insert('X');
    EXPECT_EQ(tb->getContent(), "AXB");
    EXPECT_EQ(tb->getCursorPos(), 2);
}

// ===== DELETE CHAR TESTS =====
TEST_F(TextBufferTest, DeleteCharEmptyBuffer) {
    EXPECT_THROW(tb->deleteChar(), std::out_of_range);
}

TEST_F(TextBufferTest, DeleteCharAtBeginning) {
    tb->insert('A');
    tb->moveCursorTo(0);
    EXPECT_THROW(tb->deleteChar(), std::out_of_range);
}

TEST_F(TextBufferTest, DeleteCharValid) {
    tb->insert('A');
    tb->insert('B');
    tb->moveCursorLeft();
    tb->deleteChar();
    EXPECT_EQ(tb->getContent(), "B");
    EXPECT_EQ(tb->getCursorPos(), 0);
}

TEST_F(TextBufferTest, DeleteCharAtEnd) {
    tb->insert('A');
    tb->insert('B');
    tb->deleteChar();
    EXPECT_EQ(tb->getContent(), "A");
    EXPECT_EQ(tb->getCursorPos(), 1);
}

// ===== CURSOR MOVEMENT TESTS =====
TEST_F(TextBufferTest, MoveCursorLeftEmpty) {
    EXPECT_THROW(tb->moveCursorLeft(), cursor_error);
}

TEST_F(TextBufferTest, MoveCursorRightEmpty) {
    EXPECT_THROW(tb->moveCursorRight(), cursor_error);
}

TEST_F(TextBufferTest, MoveCursorLeftValid) {
    tb->insert('A');
    tb->insert('B');
    tb->moveCursorLeft();
    EXPECT_EQ(tb->getCursorPos(), 1);
}

TEST_F(TextBufferTest, MoveCursorRightValid) {
    tb->insert('A');
    tb->insert('B');
    tb->moveCursorLeft();
    tb->moveCursorRight();
    EXPECT_EQ(tb->getCursorPos(), 2);
}

TEST_F(TextBufferTest, MoveCursorToNegative) {
    EXPECT_THROW(tb->moveCursorTo(-1), std::out_of_range);
}

TEST_F(TextBufferTest, MoveCursorToOutOfBounds) {
    tb->insert('A');
    EXPECT_THROW(tb->moveCursorTo(2), std::out_of_range);
}

TEST_F(TextBufferTest, MoveCursorToValid) {
    tb->insert('A');
    tb->insert('B');
    tb->insert('C');
    tb->moveCursorTo(1);
    EXPECT_EQ(tb->getCursorPos(), 1);
}

TEST_F(TextBufferTest, MoveCursorToBoundaries) {
    tb->insert('A');
    tb->insert('B');
    tb->moveCursorTo(0); // Should work
    tb->moveCursorTo(2); // Should work
    EXPECT_EQ(tb->getCursorPos(), 2);
}

// ===== GET CONTENT TESTS =====
TEST_F(TextBufferTest, GetContentEmpty) {
    EXPECT_EQ(tb->getContent(), "");
}

TEST_F(TextBufferTest, GetContentWithData) {
    tb->insert('H');
    tb->insert('i');
    EXPECT_EQ(tb->getContent(), "Hi");
}

// ===== FIND TESTS =====
TEST_F(TextBufferTest, FindFirstOccurrenceEmpty) {
    EXPECT_EQ(tb->findFirstOccurrence('A'), -1);
}

TEST_F(TextBufferTest, FindFirstOccurrenceNotFound) {
    tb->insert('A');
    tb->insert('B');
    EXPECT_EQ(tb->findFirstOccurrence('C'), -1);
}

TEST_F(TextBufferTest, FindFirstOccurrenceFound) {
    tb->insert('A');
    tb->insert('B');
    tb->insert('A');
    EXPECT_EQ(tb->findFirstOccurrence('A'), 0);
}

TEST_F(TextBufferTest, FindAllOccurrencesEmpty) {
    int count = 0;
    int* result = tb->findAllOccurrences('A', count);
    EXPECT_EQ(count, 0);
    delete[] result;
}

TEST_F(TextBufferTest, FindAllOccurrencesNone) {
    tb->insert('A');
    tb->insert('B');
    int count = 0;
    int* result = tb->findAllOccurrences('C', count);
    EXPECT_EQ(count, 0);
    delete[] result;
}

TEST_F(TextBufferTest, FindAllOccurrencesMultiple) {
    tb->insert('A');
    tb->insert('B');
    tb->insert('A');
    int count = 0;
    int* result = tb->findAllOccurrences('A', count);
    EXPECT_EQ(count, 2);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 2);
    delete[] result;
}

// ===== SORT TESTS =====
TEST_F(TextBufferTest, SortEmpty) {
    tb->sortAscending();
    EXPECT_EQ(tb->getContent(), "");
    EXPECT_EQ(tb->getCursorPos(), 0);
}

TEST_F(TextBufferTest, SortSingleChar) {
    tb->insert('Z');
    tb->sortAscending();
    EXPECT_EQ(tb->getContent(), "Z");
}

TEST_F(TextBufferTest, SortMultipleChars) {
    tb->insert('c');
    tb->insert('a');
    tb->insert('b');
    tb->sortAscending();
    EXPECT_EQ(tb->getContent(), "abc");
}

TEST_F(TextBufferTest, SortWithUpperCase) {
    tb->insert('c');
    tb->insert('A');
    tb->insert('b');
    tb->insert('B');
    tb->sortAscending();
    EXPECT_EQ(tb->getContent(), "ABbc");
}

// ===== DELETE ALL OCCURRENCES TESTS =====
TEST_F(TextBufferTest, DeleteAllEmpty) {
    tb->deleteAllOccurrences('A');
    EXPECT_EQ(tb->getContent(), "");
    EXPECT_EQ(tb->getCursorPos(), 0);
}

TEST_F(TextBufferTest, DeleteAllNotFound) {
    tb->insert('A');
    tb->insert('B');
    int oldCursor = tb->getCursorPos();
    tb->deleteAllOccurrences('C');
    EXPECT_EQ(tb->getContent(), "AB");
    EXPECT_EQ(tb->getCursorPos(), oldCursor);
}

TEST_F(TextBufferTest, DeleteAllFound) {
    tb->insert('A');
    tb->insert('B');
    tb->insert('A');
    tb->deleteAllOccurrences('A');
    EXPECT_EQ(tb->getContent(), "B");
    EXPECT_EQ(tb->getCursorPos(), 0);
}

TEST_F(TextBufferTest, DeleteAllEverything) {
    tb->insert('A');
    tb->insert('A');
    tb->insert('A');
    tb->deleteAllOccurrences('A');
    EXPECT_EQ(tb->getContent(), "");
    EXPECT_EQ(tb->getCursorPos(), 0);
}

// ===== UNDO/REDO TESTS =====
TEST_F(TextBufferTest, UndoEmpty) {
    tb->undo(); // Should not crash
    SUCCEED();
}

TEST_F(TextBufferTest, RedoEmpty) {
    tb->redo(); // Should not crash
    SUCCEED();
}

TEST_F(TextBufferTest, UndoInsert) {
    tb->insert('A');
    tb->undo();
    EXPECT_EQ(tb->getContent(), "");
}

TEST_F(TextBufferTest, RedoInsert) {
    tb->insert('A');
    tb->undo();
    tb->redo();
    EXPECT_EQ(tb->getContent(), "A");
}

TEST_F(TextBufferTest, UndoDelete) {
    tb->insert('A');
    tb->insert('B');
    tb->deleteChar();
    tb->undo();
    EXPECT_EQ(tb->getContent(), "AB");
}

TEST_F(TextBufferTest, MultipleUndoRedo) {
    tb->insert('A');
    tb->insert('B');
    tb->undo();
    tb->undo();
    tb->redo();
    tb->redo();
    EXPECT_EQ(tb->getContent(), "AB");
}

// Edge case: redo after new action
TEST_F(TextBufferTest, RedoAfterNewAction) {
    tb->insert('A');
    tb->undo();
    tb->insert('B'); // This should clear redo stack
    tb->redo();      // Should have no effect
    EXPECT_EQ(tb->getContent(), "B");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}