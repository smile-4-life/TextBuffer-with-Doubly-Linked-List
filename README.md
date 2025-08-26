#  TextBuffer (Data Structures & Testing | Cpp)

A simple text editor simulation implemented with a **Doubly Linked List**.  
Supports inserting/deleting characters, cursor movement, search, sort, and undo/redo.  

---

##  Highlights
- **Core logic**: template-based Doubly Linked List, TextBuffer with cursor tracking, HistoryManager for undo/redo.
- **Testing**:
  - Custom lightweight framework (`test/`)
  - Industry-standard **Google Test** integration (`test_by_ggtest/`)
- **Algorithms**: merge sort on linked lists, manual memory management, exception handling.  

---

## Structure
- ├── include/           # Header files
- ├── src/               # Core implementation
- ├── test/              # Custom test framework
- ├── test_by_ggtest/    # Unit tests with Google Test
- ├── CMakeLists.txt     # Build configuration
- └── README.md

---

## Build & Run
```bash
# Build with Google Test
mkdir build
cd build
cmake ..
cmake --build ..
cd test_by_ggtest/debug

./unittest_1
./unittest_2
```

---

## Achievement:
- Writing unit tests both from scratch and with **Google Test**.  
- Using Git for version control (branching, merging, clean commits).
- Applying **OOP principles** in C++ with templates and pointers.  
- Implementing **sorting (merge sort)** on linked lists.  

