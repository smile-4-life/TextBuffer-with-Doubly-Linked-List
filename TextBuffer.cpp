#include "TextBuffer.h"

// ----------------- DoublyLinkedList -----------------
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    this -> head = nullptr;
    this -> tail = nullptr;
    this -> count = 0;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while (this-> head != nullptr) {
        Node<T>* nextNode = this -> head -> next;
        delete this-> head;
        this -> head = nextNode;
    }
    this-> tail = nullptr;
    this-> count = 0;
}

// TODO: implement other methods of DoublyLinkedList

//set
template <typename T>
void DoublyLinkedList<T>::setHead(Node<T>* node) {
     this->head = node;
}

template <typename T>
void DoublyLinkedList<T>::setTail(Node<T>* node) {
    this->tail = node;
}

//insert
template <typename T>
void DoublyLinkedList<T>::insertAtHead(T data) {
    Node<T>* newNode = new Node<T>(data);
    newNode-> next = this-> head;
    newNode-> prev = nullptr;
    if (this-> head == nullptr) 
        this-> tail = newNode;
    else {
        this-> head-> prev = newNode;
    }
    this -> head = newNode;
    this-> count +=1;
}

template <typename T>
void DoublyLinkedList<T>::insertAtTail(T data) {
    Node<T>* newNode = new Node<T>(data);
    newNode-> prev = this-> tail;
    newNode-> next = nullptr;
    if(this-> tail == nullptr) {
        this-> head = newNode;
    }
    else {
        this-> tail-> next = newNode;
    }
    this-> tail = newNode;
    this-> count += 1;
}

template<typename T>
void DoublyLinkedList<T>::insertAt(int index, T data) {
    if ((index < 0) || (index > this-> count)) {
        throw out_of_range("Index is invalid!");
    }
    if (index == 0){
        this-> insertAtHead(data);
        return;
    }
    else if (index == this-> count){
        this-> insertAtTail(data);
        return;
    }
    else {
        Node<T>* current = this->head;
        Node<T>* newNode = new Node<T>(data);
        // x0 x1 x2
        //  0  
        for (int i = 0; i < index - 1; ++i) {
            current = current-> next;
        }
        //current *newNode current.next
        newNode-> next = current-> next;
        current-> next -> prev = newNode;
        newNode-> prev = current;
        current-> next = newNode;
        this-> count += 1;
    }
}


//delete
template <typename T>
void DoublyLinkedList<T>::deleteAt(int index) {
    if ((index < 0) || (index >= this-> count)) {
        throw out_of_range("Index is invalid!");
    }
    Node<T>* current;
    if (index == 0){
        //if (this-> head == nullptr) return; //index >= count thi` catch o? tre^n ro`i
        //else {
        current = this-> head;
        this-> head = this-> head-> next;
        if (this-> head == nullptr) this-> tail = nullptr;
        else this-> head-> prev = nullptr;
    }
    else if(index == this-> count - 1){
        current = this-> tail;
        this-> tail = this-> tail-> prev;
        this-> tail-> next = nullptr;       //crash neu tail la nullptr, nhung da duoc catch khi indec == 0
    }
    else {
        current = this-> head;
        for (int i = 0; i < index; ++i) {
            current = current-> next;
        }
        current-> prev-> next = current-> next;
        current-> next-> prev = current-> prev;
    }
    delete current;
    this-> count -= 1;
}

template <typename T>
void DoublyLinkedList<T>::removeTail() {
    if (this->count == 0) return;
    deleteAt(this->count-1);
}

//get
template <typename T>
Node<T>* DoublyLinkedList<T>::getHead() const {
    return this->head;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::getTail() const {
    return this->tail;
}

template <typename T>
T& DoublyLinkedList<T>::get(int index) const {
    if ((index < 0) || (index >= this-> count)) {
        throw out_of_range("Index is invalid!");
    }
    Node<T>* current = this-> head;
    //x0 x1 x2
    // 0  1 
    for (int i = 0; i < index; ++i) {
        current = current-> next;
    }
    return current-> data;        
}

template <typename T>
int DoublyLinkedList<T>::size() const{
    return this-> count;
}




template <typename T>
int DoublyLinkedList<T>::indexOf(T item) const {
    Node<T>* current = this-> head;
    for(int index = 0; index < this-> count; index++) {
        if(current-> data == item) return index;
        else current = current-> next;
    }
    return -1;
}

template <typename T>
bool DoublyLinkedList<T>::contains(T item) const {
    Node<T>* current = this-> head;
    for(int index = 0; index < this-> count; index++) {
        if(current-> data == item) return true;
        else current = current-> next;
    }
    return false;
}

template <typename T>
void DoublyLinkedList<T>::reverse() {
    if (this->head == nullptr || this->count <= 1) return;
    Node<T>* temp;
    Node<T>* current = this-> head;
    while (current != nullptr) {
        temp = current-> next;
        current -> next = current-> prev;
        current -> prev = temp;

        current = current-> prev;
    }
    temp = this-> head ;
    this-> head = this-> tail;
    this-> tail = temp;
}

template <typename T>
string DoublyLinkedList<T>::toString(string(*convert2str)(T&)) const {
    Node<T>* current = this-> head;
    string result = "[";
    bool firstElement = true;
    while(current != nullptr) {
        if (!firstElement)
            result += ", ";
        else firstElement = false;
        if (convert2str != nullptr) {
            result += convert2str(current-> data);
        }
        else {
            std::ostringstream temp_result;
            temp_result << current-> data;   
            result += temp_result.str();
        }
        current = current-> next;
    }
    result += "]";
    return result;
}

// ----------------- TextBuffer -----------------
TextBuffer::TextBuffer() {
    this-> buffer = DoublyLinkedList<char>();
    this-> cursorPos = 0;
    this-> History = new HistoryManager();
}

TextBuffer::~TextBuffer() {
    delete this->History;
    this->History= nullptr;
}

// TODO: implement other methods of TextBuffer
void TextBuffer::insert(char c) {
    this->buffer.insertAt(this-> cursorPos, c);
    this->History->clearRedo();
    this->History->addAction("insert", this->cursorPos, c);
    this-> cursorPos++;
    return;
}

void TextBuffer::deleteChar() {
    int deletedIndex = --this->cursorPos;
    char deletedChar = this->buffer.get(deletedIndex);
    buffer.deleteAt(deletedIndex);
    this->History->clearRedo();
    this->History->addAction("delete", deletedIndex+1, deletedChar);
    return;
}

void TextBuffer::moveCursorLeft() {
    this->History->addAction("move", this->cursorPos, 'L');

    if (this-> cursorPos == 0)
        throw cursor_error();
    this-> cursorPos--;
    return;
}

void TextBuffer::moveCursorRight() {
    this->History->addAction("move", this->cursorPos, 'R');

    if (this-> cursorPos == this-> buffer.size())
        throw cursor_error();
    this-> cursorPos++; 
    return;
}

void TextBuffer::moveCursorTo(int index) {
    if (index < 0 || index > this-> buffer.size())
        throw out_of_range("Index is invalid!");
    this->History->addAction("move", this->cursorPos, 'J');
    this-> cursorPos = index;
    this->History->indexJump.insertAtTail(index);
    return;
}

string TextBuffer::getContent() const {
    Node<char>* current = this->buffer.getHead();
    string result;
    while(current != nullptr) {
        result += (current->data);
        current = current->next;
    }
    return result;
}

int TextBuffer::getCursorPos() const {
    return this-> cursorPos;
}

int TextBuffer::findFirstOccurrence(char c) const {
    return this-> buffer.indexOf(c);
}

int* TextBuffer:: findAllOccurrences(char c, int&count) const {
    count = 0;
    int* arr = nullptr;
    Node<char>* current = this-> buffer.getHead();
    int currentIndex = 0;
    while(current != nullptr) {
        if(current-> data == c) {
            addToArr(arr, currentIndex, ++count);
        }
        current = current-> next;
        currentIndex++;
    }
    return arr;
}


///// SORT

int charOrder(char c) {
    if (c >= 'A' && c <= 'Z') {
        return (c - 'A') * 2;
    } else if (c >= 'a' && c <= 'z') {
        return (c - 'a') * 2 + 1;
    } else {
        return 1000 + c;  // ký tự đặc biệt xếp cuối
    }
}

template<typename T>
int charOrder(T x) {
    return 0;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::getMiddle(Node<T>* head) {
    if (!head) return head;
    Node<T>* slow = head;
    Node<T>* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::sortedMerge(Node<T>* a, Node<T>* b) {
    if (!a) return b;
    if (!b) return a;

    if (charOrder(a->data) <= charOrder(b->data)) {
        a->next = sortedMerge(a->next, b);
        if (a->next) a->next->prev = a;
        a->prev = nullptr;
        return a;
    } else {
        b->next = sortedMerge(a, b->next);
        if (b->next) b->next->prev = b;
        b->prev = nullptr;
        return b;
    }
}

template <typename T>
Node<T>* DoublyLinkedList<T>::mergeSort(Node<T>* head) {
    if (!head || !head->next) return head;

    Node<T>* mid = getMiddle(head);
    Node<T>* second = mid->next;
    mid->next = nullptr;
    if (second) second->prev = nullptr;

    Node<T>* left = mergeSort(head);
    Node<T>* right = mergeSort(second);

    return sortedMerge(left, right);
}

void TextBuffer::sortAscending() {
    string snapShot = this->getContent();
    this->History->snapShot.insertAtTail(snapShot);

    this->History->addAction("sort", this->cursorPos, '\0');
    if (this->buffer.size() <= 1) return;

    // Gọi merge sort
    this->buffer.setHead ( this->buffer.mergeSort(this->buffer.getHead()) );

    // Cập nhật lại tail
    this->buffer.setTail ( this->buffer.getHead() );
    while (this->buffer.getTail() && this->buffer.getTail()->next)
        this->buffer.setTail( this->buffer.getTail()->next );

    // Reset con trỏ về đầu
    this->cursorPos = 0;
    
}

///// END SORT

void TextBuffer::deleteAllOccurrences(char c) {
    Node<char>* current = this->buffer.getHead();
    int index = 0;
    while(current != nullptr) {
        Node<char>* nextNode = current-> next;
        if (current->data == c) {
            this->buffer.deleteAt(index);
            this->cursorPos--;
        }
        else {
            index++;
        }
        current = nextNode;
    }
}

void TextBuffer::undo() {
    Action C = this->History->undoAction();
    if (C.name == "insert") {
        this->buffer.deleteAt(C.cursorPos);
    }   
    if (C.name == "delete") {
        this->buffer.insertAt(C.cursorPos - 1, C.c);
    }
    if (C.name == "move") {

    }
    if (C.name == "sort") {
        Node<string>* SnapShot = this->History->snapShot.getTail();
        string snapShot = SnapShot->data;
        this->History->snapShot.removeTail();
        int i = 0;
        Node<char>* current = this->buffer.getHead();
        while(i < snapShot.length()) {
            current->data = snapShot[i];
            i = i + 1;
            current = current->next;
        }
    }
    if(C.name == "") {
        return;
    }
    this->cursorPos = C.cursorPos;
}

void TextBuffer::redo() {
    Action C = this->History->redoAction();
    char c = C.c;
    if (C.name == "insert") {
        this->buffer.insertAt(C.cursorPos, c);
        this->cursorPos = C.cursorPos+1;
    }   
    if (C.name == "delete") {
        this->buffer.deleteAt(C.cursorPos-1);
        this->cursorPos = C.cursorPos-1;
    }
    if (C.name == "move") {
        if (C.c == 'L') this->cursorPos = C.cursorPos - 1;
        else if (C.c == 'R') this->cursorPos = C.cursorPos + 1;
        else {
            Node<int>* indexNode = this->History->indexJump.getTail();
            this->History->indexJump.removeTail();
            this->cursorPos = indexNode->data;
        }
    }
    if (C.name == "sort") {
        this->sortAscending();
    }
    if (C.name == "") {
        return;
    }
}

// ----------------- HistoryManager -----------------
TextBuffer::HistoryManager::HistoryManager() {
    // TODO
}

TextBuffer::HistoryManager::~HistoryManager() {
    // TODO
}

//TODO: implement other methods of HistoryManager


// Explicit template instantiation for char, string, int, double, float, and Point
template class DoublyLinkedList<char>;
template class DoublyLinkedList<string>;
template class DoublyLinkedList<int>;
template class DoublyLinkedList<double>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<Point>;