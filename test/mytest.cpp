#include "mytest.h"
#include "TextBuffer.h"
#include "sample_list.h"

// ===== DoublyLinkedList =====

// void insertAtHead(T data)
void sample_01() {
    DoublyLinkedList<int> dll;
    dll.insertAtHead(2); dll.insertAtHead(1);
    cout << "sample_01: " << dll.toString() << endl;
}
string expected_01() { return "sample_01: [1, 2]"; }

// void insertAtTail(T data)
void sample_02() {
    DoublyLinkedList<char> dll;
    dll.insertAtTail('A'); dll.insertAtTail('B');
    cout << "sample_02: " << dll.toString() << endl;
}
string expected_02() { return "sample_02: [A, B]"; }

// insertAt(int index, T data)
void sample_03() {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1); dll.insertAtTail(3); dll.insertAt(1, 2);
    cout << "sample_03: " << dll.toString() << endl;
}
string expected_03() { return "sample_03: [1, 2, 3]"; }

// insertAt with invalid index (negative)
void sample_04() {
    try {
        DoublyLinkedList<int> dll;
        cout << "sample_04: (test out of range)\n";
        dll.insertAtTail(1); dll.insertAtTail(3); dll.insertAt(-1, 2);
    }
    catch (const out_of_range &e) {
        cout << e.what() << endl;
    }
}
string expected_04() { return "sample_04: (test out of range)\nIndex is invalid!"; }

// insertAt with invalid index (greater than size)
void sample_05() {
    try {
        DoublyLinkedList<int> dll;
        cout << "sample_05: (test out of range)\n";
        dll.insertAtTail(1); dll.insertAtTail(3); dll.insertAt(3, 2);
    }
    catch (const out_of_range &e) {
        cout << e.what() << endl;
    }
}
string expected_05() { return "sample_05: (test out of range)\nIndex is invalid!"; }

// T& get(int index)
void sample_06() {
    DoublyLinkedList<string> dll;
    dll.insertAtTail("Hello");
    cout << "sample_06: " << dll.get(0) << endl;
}
string expected_06() { return "sample_06: Hello"; }

// int indexOf(T item)
void sample_07() {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(5); dll.insertAtTail(10);
    cout << "sample_07: " << dll.indexOf(10) << endl;
}
string expected_07() { return "sample_07: 1"; }

// get with invalid index (negative)
void sample_08() {
    DoublyLinkedList<string> dll;
    dll.insertAtTail("Hello");
    cout << "sample_08: (test out of range)\n";
    try {
        dll.get(-1);
    }
    catch (const out_of_range &e) {
        cout << e.what() << endl;
    }
}
string expected_08() { return "sample_08: (test out of range)\nIndex is invalid!"; }

// get with invalid index (greater than size)
void sample_09() {
    DoublyLinkedList<string> dll;
    dll.insertAtTail("Hello");
    cout << "sample_09: (test out of range)\n";
    try {
        dll.get(2);
    }
    catch (const out_of_range &e) {
        cout << e.what() << endl;
    }
}
string expected_09() { return "sample_09: (test out of range)\nIndex is invalid!"; }

// bool contains(T item) - true case
void sample_10() {
    DoublyLinkedList<char> dll;
    dll.insertAtTail('A'); dll.insertAtTail('B');
    cout << "sample_10: " << (dll.contains('B') ? "true" : "false") << endl;
}
string expected_10() { return "sample_10: true"; }

// bool contains(T item) - false case
void sample_11() {
    DoublyLinkedList<char> dll;
    dll.insertAtTail('A'); dll.insertAtTail('B');
    cout << "sample_11: " << (dll.contains('C') ? "true" : "false") << endl;
}
string expected_11() { return "sample_11: false"; }

// void deleteAt(int index)
void sample_12() {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1); dll.insertAtTail(2);
    dll.deleteAt(0);
    cout << "sample_12: " << dll.toString() << endl;
}
string expected_12() { return "sample_12: [2]"; }

// int size()
void sample_13() {
    DoublyLinkedList<int> dll;
    dll.insertAtTail(1); dll.insertAtTail(2); dll.insertAtTail(3);
    cout << "sample_13: " << dll.size() << endl;
}
string expected_13() { return "sample_13: 3"; }

// void reverse()
void sample_14() {
    DoublyLinkedList<char> dll;
    dll.insertAtTail('x'); dll.insertAtTail('y'); dll.insertAtTail('z');
    dll.reverse();
    cout << "sample_14: " << dll.toString() << endl;
}
string expected_14() { return "sample_14: [z, y, x]"; }

// string toString()
void sample_15() {
    DoublyLinkedList<string> dll;
    dll.insertAtTail("a"); dll.insertAtTail("b");
    cout << "sample_15: " << dll.toString() << endl;
}
string expected_15() { return "sample_15: [a, b]"; }

// ===== TextBuffer =====

// void insert(char)
void sample_16() {
    TextBuffer tb;
    tb.insert('H'); tb.insert('e'); tb.insert('y');
    cout << "sample_16: " << tb.getContent() << endl;
}
string expected_16() { return "sample_16: Hey"; }

// void moveCursorLeft()
void sample_17() {
    TextBuffer tb;
    tb.insert('A'); tb.insert('B'); tb.insert('C');
    tb.moveCursorLeft(); tb.insert('X');
    cout << "sample_17: " << tb.getContent() << endl;
}
string expected_17() { return "sample_17: ABXC"; }

// void moveCursorLeft() error case
void sample_18() {
    cout << "sample_18: (test cursor error)" << endl;
    TextBuffer tb;
    try {
        tb.moveCursorLeft();
    }
    catch(const cursor_error &e) {
        cout << e.what() << endl;
    }
}
string expected_18() { return "sample_18: (test cursor error)\nCursor error!"; }

// void moveCursorRight()
void sample_19() {
    TextBuffer tb;
    tb.insert('1'); tb.insert('2'); tb.moveCursorLeft();
    tb.moveCursorRight(); tb.insert('3');
    cout << "sample_19: " << tb.getContent() << endl;
}
string expected_19() { return "sample_19: 123"; }

// void moveCursorRight() error case
void sample_20() {
    cout << "sample_20: (test error cursor)\n";
    TextBuffer tb;
    tb.insert('1'); tb.insert('2'); 
    try {
        tb.moveCursorRight();
    }
    catch (const cursor_error &e) {
        cout << e.what() << endl;
    }
}
string expected_20() { return "sample_20: (test error cursor)\nCursor error!"; }

// void moveCursorTo(int)
void sample_21() {
    TextBuffer tb;
    tb.insert('m'); tb.insert('n'); tb.insert('p');
    tb.moveCursorTo(1); tb.insert('-');
    cout << "sample_21: " << tb.getContent() << endl;
}
string expected_21() { return "sample_21: m-np"; }

// void moveCursorTo(int) error case (negative index)
void sample_22() {
    cout << "sample_22: (test error cursor)" << endl;
    TextBuffer tb;
    tb.insert('m'); tb.insert('n'); tb.insert('p');
    try {
        tb.moveCursorTo(-1);
    }
    catch (const out_of_range &e) {
        cout << e.what() << endl;
    } 
}
string expected_22() { return "sample_22: (test error cursor)\nIndex is invalid!"; }

// void moveCursorTo(int) error case (index > size)
void sample_23() {
    cout << "sample_23: (test error cursor)" << endl;
    TextBuffer tb;
    tb.insert('m'); tb.insert('n'); tb.insert('p');
    try {
        tb.moveCursorTo(4);
    }
    catch (const out_of_range &e) {
        cout << e.what() << endl;
    } 
}
string expected_23() { return "sample_23: (test error cursor)\nIndex is invalid!"; }

// void deleteChar()
void sample_24() {
    TextBuffer tb;
    tb.insert('a'); tb.insert('b'); tb.insert('c');
    tb.moveCursorLeft(); tb.moveCursorLeft();
    tb.deleteChar();
    cout << "sample_24: " << tb.getContent() << endl;
}
string expected_24() { return "sample_24: bc"; }

// undo and redo
void sample_25() {
    TextBuffer tb;
    tb.insert('a'); tb.insert('b'); tb.undo(); tb.redo();
    cout << "sample_25: " << tb.getContent() << endl;
}
string expected_25() { return "sample_25: ab"; }


// findFirstOccurrence
void sample_26() {
    TextBuffer tb;
    tb.insert('a'); tb.insert('b'); tb.insert('c'); tb.insert('b');
    cout << "sample_26: " << tb.findFirstOccurrence('b') << endl;
}
string expected_26() { return "sample_26: 1"; }

// insert → delete → undo (restore character)
void sample_27() {
    TextBuffer tb;
    tb.insert('m'); tb.insert('n'); tb.moveCursorLeft(); tb.deleteChar(); tb.undo();
    cout << "sample_27: " << tb.getContent() << endl;
}
string expected_27() { return "sample_27: mn"; }

// insert → delete → undo → redo (delete again)
void sample_28() {
    TextBuffer tb;
    tb.insert('p'); tb.insert('q'); tb.moveCursorLeft(); tb.deleteChar(); tb.undo(); tb.redo();
    cout << "sample_28: " << tb.getContent() << endl;
}
string expected_28() { return "sample_28: q"; }

// multiple undo → multiple redo
void sample_29() {
    TextBuffer tb;
    tb.insert('a'); tb.insert('b'); tb.insert('c');
    tb.undo(); tb.undo(); tb.redo(); tb.redo();
    cout << "sample_29: " << tb.getContent() << endl;
}
string expected_29() { return "sample_29: abc"; }

// undo after moveCursorLeft (shouldn't affect undo stack)
void sample_30() {
    TextBuffer tb;
    tb.insert('1'); tb.insert('2'); tb.moveCursorLeft(); tb.undo();
    cout << "sample_30: " << tb.getContent() << endl;
}
string expected_30() { return "sample_30: 12"; }

// undo after moveCursorTo (shouldn't affect undo stack)
void sample_31() {
    TextBuffer tb;
    tb.insert('x'); tb.insert('y'); tb.moveCursorTo(0); tb.undo();
    cout << "sample_31: " << tb.getContent() << " | ";
    cout << "cursorPos: " << tb.getCursorPos();
}
string expected_31() { return "sample_31: xy | cursorPos: 2"; }

// insert → sort → undo → redo
void sample_32() {
    TextBuffer tb;
    tb.insert('c'); tb.insert('a'); tb.insert('b');
    tb.insert('C'); tb.insert('B'); tb.insert('A');
    cout << "sample_32: ";
    cout << "Before sort: " << tb.getContent() << " ";
    tb.sortAscending();
    cout << "After sort: " << tb.getContent() << " ";
    tb.undo();
    cout << "After undo: " << tb.getContent() << " ";
    tb.redo();
    cout << "After redo: " << tb.getContent() << " ";
}
string expected_32() {
    return "sample_32: "
           "Before sort: cabCBA "
           "After sort: AaBbCc "
           "After undo: cabCBA "
           "After redo: AaBbCc ";
}

// delete → insert → redo (redo should have no effect)
void sample_33() {
    TextBuffer tb;
    tb.insert('q'); tb.insert('w'); tb.moveCursorLeft(); tb.deleteChar();
    tb.undo(); tb.insert('e'); tb.redo();
    cout << "sample_33: " << tb.getContent() << endl;
}
string expected_33() { return "sample_33: qew"; }

// insert → undo → redo x2 (redo should only work once)
void sample_34() {
    TextBuffer tb;
    tb.insert('a'); tb.insert('b'); tb.undo(); tb.redo(); tb.redo();
    cout << "sample_34: " << tb.getContent() << endl;
}
string expected_34() { return "sample_34: ab"; }

// findFirstOccurrence
void sample_35() {
    TextBuffer tb;
    tb.insert('a'); tb.insert('b'); tb.insert('c'); tb.insert('b');
    cout << "sample_35: " << tb.findFirstOccurrence('b') << endl;
}
string expected_35() { return "sample_35: 1"; }

// findAllOccurrences
void sample_36() {
    TextBuffer tb;
    tb.insert('x'); tb.insert('y'); tb.insert('x'); tb.insert('z'); tb.insert('x');
    int count = 0;
    int* indices = tb.findAllOccurrences('x', count);
    cout << "sample_36: ";
    for (int i = 0; i < count; i++) cout << indices[i] << " ";
    cout << endl;
    delete[] indices;
}
string expected_36() { return "sample_36: 0 2 4 "; }

// deleteAllOccurrences
void sample_37() {
    TextBuffer tb;
    tb.insert('a'); tb.insert('b'); tb.insert('a'); tb.insert('c'); tb.insert('a');
    tb.deleteAllOccurrences('a');
    cout << "sample_37: " << tb.getContent() << endl;
}
string expected_37() { return "sample_37: bc"; }





// Additional edge cases for TextBuffer

// deleteChar at beginning (should throw)
void sample_38() {
    cout << "sample_38: (test error)\n";
    TextBuffer tb;
    try {
        tb.deleteChar();
    }
    catch (const out_of_range &e) {
        cout << e.what() << endl;
    }
}
string expected_38() { return "sample_38: (test error)\nIndex is invalid!"; }

// multiple undo when nothing to undo
void sample_39() {
    TextBuffer tb;
    tb.insert('A'); tb.insert('B');
    tb.undo(); tb.undo(); tb.undo(); tb.undo();
    cout << "sample_39: " << tb.getContent() << endl;
}
string expected_39() { return "sample_39: "; }

// deleteAll on empty buffer
void sample_40() {
    TextBuffer tb;
    tb.deleteAllOccurrences('a');
    cout << "sample_40: " << tb.getContent() << endl;
}
string expected_40() { return "sample_40: "; }

// sort empty buffer
void sample_41() {
    TextBuffer tb;
    tb.sortAscending();
    cout << "sample_41: " << tb.getContent() << endl;
}
string expected_41() { return "sample_41: "; }

// find in empty buffer
void sample_42() {
    TextBuffer tb;
    cout << "sample_42: " << tb.findFirstOccurrence('a') << endl;
}
string expected_42() { return "sample_42: -1"; }

// ===== Combined Tests =====

// complex sequence of operations
void sample_43() {
    TextBuffer tb;
    tb.insert('a'); tb.insert('b'); tb.insert('c');
    tb.moveCursorLeft(); tb.deleteChar();
    tb.undo(); tb.redo();
    tb.insert('x'); tb.sortAscending();
    cout << "sample_43: " << tb.getContent() << endl;
}
string expected_43() { return "sample_43: acx"; }

// stress test with many operations
void sample_44() {
    TextBuffer tb;
    for (char c : {'z', 'y', 'x', 'w', 'v'}) tb.insert(c);
    tb.sortAscending();
    tb.moveCursorTo(5);
    for (int i = 0; i < 3; i++) tb.deleteChar();
    tb.undo(); tb.undo();
    cout << "sample_44: " << tb.getContent() << endl;
}
string expected_44() { return "sample_44: vwxy"; }

// test cursor position after multiple operations
void sample_45() {
    TextBuffer tb;
    tb.insert('A'); tb.insert('B'); tb.insert('C');
    tb.moveCursorTo(2); tb.deleteChar();
    tb.moveCursorLeft(); tb.insert('X');
    cout << "sample_45: " << tb.getContent() << ", cursor: " << tb.getCursorPos() << endl;
}
string expected_45() { return "sample_45: XAC, cursor: 1"; }






void sample_46() {
    TextBuffer tb;
    tb.insert('A'); tb.insert('B'); tb.moveCursorTo(0); tb.insert('X');
    tb.undo(); tb.undo(); tb.undo(); tb.undo();
    cout << "sample_46: " << tb.getContent() << endl;
}
string expected_46() { return "sample_46: "; }

void sample_47() {
    TextBuffer tb;
    tb.insert('T'); tb.insert('e'); tb.insert('s'); tb.insert('t');
    tb.moveCursorTo(4);
    cout << "sample_47: cursor = " << tb.getCursorPos() << endl;
}
string expected_47() { return "sample_47: cursor = 4"; }

void sample_48() {
    TextBuffer tb;
    tb.insert('a'); tb.insert('b'); tb.insert('c'); tb.moveCursorLeft();
    tb.moveCursorLeft(); tb.insert('X'); tb.deleteChar(); tb.undo();
    cout << "sample_48: " << tb.getContent() << endl;
}
string expected_48() { return "sample_48: aXbc"; }

void sample_49() {
    TextBuffer tb;
    tb.insert('1'); tb.insert('2'); tb.insert('3');
    tb.sortAscending(); tb.moveCursorRight(); tb.deleteChar(); tb.undo();
    cout << "sample_49: " << tb.getContent() << endl;
}
string expected_49() { return "sample_49: 123"; }

void sample_50() {
    TextBuffer tb;
    tb.insert('a'); tb.insert('A'); tb.insert('b'); tb.insert('B');
    tb.sortAscending(); tb.undo(); tb.sortAscending(); tb.sortAscending();
    cout << "sample_50: " << tb.getContent() << endl;
}
string expected_50() { return "sample_50: AaBb"; }

void sample_51() {
    cout << "sample_51:" << endl;
    DoublyLinkedList<char> dll;
    dll.insertAtTail('A');
    try {
        dll.get(5);
    } catch (const out_of_range &e) {
        cout << e.what() << endl;
    }
}
string expected_51() { return "sample_51:\nIndex is invalid!"; }

void sample_52() {
    cout << "sample_52:" << endl;
    DoublyLinkedList<char> dll;
    try {
        dll.insertAt(-1, 'X');
    } catch (const out_of_range &e) {
        cout << e.what() << endl;
    }
}
string expected_52() { return "sample_52:\nIndex is invalid!"; }

void sample_53() {
    cout << "sample_53:" << endl;
    DoublyLinkedList<char> dll;
    dll.insertAtTail('A');
    try {
        dll.insertAt(2, 'B');
    } catch (const out_of_range &e) {
        cout << e.what() << endl;
    }
}
string expected_53() { return "sample_53:\nIndex is invalid!"; }

void sample_54() {
    cout << "sample_54:" << endl;
    DoublyLinkedList<char> dll;
    dll.insertAtTail('A');
    try {
        dll.deleteAt(-1);
    } catch (const out_of_range &e) {
        cout << e.what() << endl;
    }
}
string expected_54() { return "sample_54:\nIndex is invalid!"; }

void sample_55() {
    cout << "sample_55:" << endl;
    DoublyLinkedList<char> dll;
    dll.insertAtTail('A');
    try {
        dll.deleteAt(1);
    } catch (const out_of_range &e) {
        cout << e.what() << endl;
    }
}
string expected_55() { return "sample_55:\nIndex is invalid!"; }

void sample_56() {
    cout << "sample_56:" << endl;
    TextBuffer tb;
    tb.insert('A');
    tb.moveCursorTo(0);
    try {
        tb.moveCursorLeft();
    } catch (const cursor_error &e) {
        cout << e.what() << endl;
    }
}
string expected_56() { return "sample_56:\nCursor error!"; }

void sample_57() {
    cout << "sample_57:" << endl;
    TextBuffer tb;
    tb.insert('A');
    tb.moveCursorTo(1);
    try {
        tb.moveCursorRight();
    } catch (const cursor_error &e) {
        cout << e.what() << endl;
    }
}
string expected_57() { return "sample_57:\nCursor error!"; }

void sample_58() {
    cout << "sample_58:" << endl;
    TextBuffer tb;
    tb.insert('a');
    try {
        tb.moveCursorTo(-1);
    } catch (const out_of_range &e) {
        cout << e.what() << endl;
    }
}
string expected_58() { return "sample_58:\nIndex is invalid!"; }

void sample_59() {
    cout << "sample_59:" << endl;
    TextBuffer tb;
    tb.insert('a');
    try {
        tb.moveCursorTo(5);
    } catch (const out_of_range &e) {
        cout << e.what() << endl;
    }
}
string expected_59() { return "sample_59:\nIndex is invalid!"; }

void sample_60() {
    cout << "sample_60:" << endl;
    TextBuffer tb;
    try {
        tb.deleteChar();  // cursorPos = 0
    } catch (const out_of_range &e) {
        cout << e.what() << endl;
    }
}
string expected_60() { return "sample_60:\nIndex is invalid!"; }



int main() {
    #define X(sample, expect) REGISTER_SAMPLE(sample, expect(), #sample);
    SAMPLE_LIST
    #undef X
    TEST_RUNNER();
    return 0;
}
