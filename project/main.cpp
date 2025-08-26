#include "TextBuffer.h"

int main(int argc, char** argv) {
    TextBuffer tb;
    tb.insert('a');
    tb.insert('b');
    tb.insert('A');
    tb.sortAscending();
    tb.printHistory();
    cout << endl << '\0' << endl;
    return 0;
}
