#include "TextBuffer.h"

// ----------------- DoublyLinkedList -----------------
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    // TODO
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    // TODO
}

// TODO: implement other methods of DoublyLinkedList

// ----------------- TextBuffer -----------------
TextBuffer::TextBuffer() {
    // TODO
}

TextBuffer::~TextBuffer() {
    // TODO
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