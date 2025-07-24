#ifndef __TEXT_BUFFER_H__
#define __TEXT_BUFFER_H__

#include "main.h"

struct Action {
            string name;
            int cursorPos;
            char c;

            Action();
            Action(string name, int pos, char c);
            ~Action();
        };

template <typename T>
class Node {
public:
    Node* prev;
    Node* next;
    T data;

    Node(T d) : data(d), prev(nullptr), next(nullptr) {};
};

template <typename T>
class DoublyLinkedList {    
    // TODO: may provide some attributes
private:
    Node<T>* head;
    Node<T>* tail;
    int count;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insertAtHead(T data);
    void insertAtTail(T data);
    void insertAt(int index, T data);
    void deleteAt(int index);
    T& get(int index) const;
    int indexOf(T item) const;
    bool contains(T item) const;
    int size() const;
    void reverse();
    string toString(string (*convert2str)(T&) = 0) const;

    //function for sort
    Node<T>* getMiddle(Node<T>* head);
    Node<T>* sortedMerge(Node<T>* a, Node<T>* b);
    Node<T>* mergeSort(Node<T>* head);

    //get
    Node<T>* getHead() const;
    Node<T>* getTail() const;

    //set
    void setHead(Node<T>* node);
    void setTail(Node<T>* node);
    void removeTail();
};

class TextBuffer {
public:
    TextBuffer();
    ~TextBuffer();

    void insert(char c);
    void deleteChar();
    void moveCursorLeft();
    void moveCursorRight();
    void moveCursorTo(int index);
    string getContent() const;
    int getCursorPos() const;
    int findFirstOccurrence(char c) const;
    int* findAllOccurrences(char c, int &count) const;
    void sortAscending();
    void deleteAllOccurrences(char c);
    void undo();
    void redo();

public:
    class HistoryManager {
        // TODO: may provide some attributes

    public:     
        HistoryManager();
        ~HistoryManager();

        void addAction(const string &actionName, int cursorPos, char c);
        void printHistory() const;
        int size() const;

        Action undoAction();
        Action redoAction();
        void clearRedo();
  
    
    public:
        DoublyLinkedList<Action> HistoryActions; //một DDL về các action
        DoublyLinkedList<Action> UndoAction;
        DoublyLinkedList<string> snapShot;
        DoublyLinkedList<int> indexJump;
    };

private:
    DoublyLinkedList<char> buffer; 
    int cursorPos;
    HistoryManager* History;
};

#endif // __TEXT_BUFFER_H__

