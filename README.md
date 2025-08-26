
# 📝 TextBuffer - CO2003 Assignment 1

> A text editor simulation using Doubly Linked List, designed for the CO2003 Data Structures and Algorithms course at HCMUT.

---

## 1. Introduction

**TextBuffer** is a simple program that simulates how a basic text editor works. It is built using basic data structures, mainly a **Doubly Linked List (DDL)**. Instead of using built-in types like strings or arrays, it stores and edits each character one by one through connected nodes, similar to how real text editors work behind the scenes.

Although it is made for learning purposes, this program still supports common text editing features such as adding and deleting characters, moving the cursor, sorting the text, and undoing or redoing actions. It helps practice how data structures are used in real applications.
## Potential Extensions

- File I/O (load/save text)
- Copy/paste/select operations
- Syntax highlighting logic
- GUI support (e.g. ncurses, Qt)

---

## 3. What I Learned

This project helped me grow in both technical and professional skills:

-  Mastered OOP design in C++
-  Implemented `template`-based generic structures
-  Manual memory & pointer management
-  Merge sort algorithm on linked lists
-  Undo/redo using two-stack logic
-  Developed over 60+ unit tests (TDD)
-  Used **GitHub** professionally: branching, merging, clean commits, pull requests

---

## 4. Project Structure

<img width="814" height="277" alt="image" src="https://github.com/user-attachments/assets/4f2880fb-4f8d-47da-b646-5083b30c594f" />

---

## 5. Features

### 5.1 TextBuffer
- Insert/delete characters
- Cursor movement and position tracking
- Search operations (first/all occurrences)
- Sort characters with custom order
- Undo/redo system (history tracking)

### 5.2 HistoryManager
- Records all user actions
- Enables reversible edits with redo logic

### 5.3 DoublyLinkedList<T>
- Template-based
- Supports reverse, get, insert/remove
- Merge sort with character comparison

---

## 6. Testing

### 6.1 How to Run Tests
```bash
g++ -o test_runner test/mytest.cpp project/TextBuffer.cpp -I project -std=c++17
./test_runner
```
### 6.2 Coverage:  
-  DLL logic: insert, delete, reverse, indexOf

-  Buffer logic: cursor, edit, sort, search

-  Undo/redo correctness

-  Exception handling

## 7 Compilation
```bash
g++ -o main main.cpp TextBuffer.cpp -I . -std=c++17
./main
```

📜 License
This project is for academic use only as part of CO2003 @ HCMUT.

👤 Author
Student: CO2003 - HCMUT
Semester: HK3 (2024–2025)

---
