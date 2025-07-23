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