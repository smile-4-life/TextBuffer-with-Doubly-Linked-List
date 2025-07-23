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