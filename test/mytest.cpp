#include "mytest.h"
#include "TextBuffer.h"
#include "sample_list.h"


void sample_01() {
    DoublyLinkedList<int> dll;
    dll.insertAtHead(2); dll.insertAtHead(1);
    cout << "sample_01: " << dll.toString() << endl;
}
string expected_01() { return "sample_01: [1, 2]"; }

int main() {
    #define X(sample, expect) REGISTER_SAMPLE(sample, expect(), #sample);
    SAMPLE_LIST
    #undef X
    TEST_RUNNER();
    return 0;
}
