# 📚 Programming Concepts Assignment 4

<div align="center">

![C Programming](https://img.shields.io/badge/C-Programming-00599C?style=for-the-badge&logo=c&logoColor=white)
![Assignment](https://img.shields.io/badge/Assignment-4-brightgreen?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)

[![Ask DeepWiki](https://deepwiki.com/badge.svg)](https://deepwiki.com/muhammadghiffari/programming-concepts-assignment4)
![Lines of Code](https://img.shields.io/badge/Lines%20of%20Code-377-blue?style=flat-square)
![Files](https://img.shields.io/badge/Files-2-orange?style=flat-square)
![Language](https://img.shields.io/badge/Language-C-A8B9CC?style=flat-square&logo=c)
![License](https://img.shields.io/badge/License-Educational-yellow?style=flat-square)

**Array Operations & Data Management in C**

Built by **Muhammad Ghiffari** ([@muhammadghiffari](https://github.com/muhammadghiffari)) and **Fhutka Hiban Dairoby** ([@hicesse](https://github.com/hicesse))

[Overview](#-overview) • [Programs](#-programs) • [Installation](#-installation) • [Usage](#-usage)

</div>

---

## 📋 Table of Contents

- [Overview](#-overview)
- [Programs](#-programs)
  - [Problem 1: Grade Management System](#problem-1-grade-management-system)
  - [Problem 2: Product Price Inventory](#problem-2-product-price-inventory)
- [Features Comparison](#-features-comparison)
- [Installation](#-installation)
- [Usage](#-usage)
- [Technical Details](#-technical-details)
- [Team](#-team)

---

## 🌟 Overview

This repository contains two C programs demonstrating fundamental data structures and algorithms concepts. Each program showcases different approaches to array manipulation, sorting, searching, and user interaction.

**Assignment Requirements**: Choose 2 out of 3 problems focusing on:
- Array operations and management
- Sorting algorithms implementation
- Search algorithms (Binary & Linear)
- Function modularization
- Input validation and error handling

---

## 💻 Programs

### Problem 1: Grade Management System

**File**: `problem1.c` | **Lines**: 180 | **Architecture**: Interactive Menu-Driven

An interactive student grade management system with state preservation and advanced validation.

#### Key Features
- ✅ Interactive menu with 5 options
- ✅ Dual array architecture (preserves original data)
- ✅ Binary search algorithm (O(log n))
- ✅ Ascending sort implementation
- ✅ State machine with operation guards
- ✅ Before/after comparison view

#### Functions
```c
void greet()                              // Display menu
void shortingArr(int arr[], int n)        // Bubble sort ascending
void showGrade(int arr[], int n)          // Display current grades
void showGradeB(int arr[], int n)         // Display original grades
void search(int arr[], int n, int value)  // Binary search
int error()                               // Error handling
```

#### Usage Flow
```
1. Input grades (0-100)
   → Stored in arr[] and arrB[]
   
2. Sort grades (ascending)
   → Modifies arr[] only
   
3. Search for specific grade
   → Binary search (requires sorted data)
   
4. Display before/after comparison
   → Shows arrB[] vs arr[]
   
5. Exit program
```

---

### Problem 2: Product Price Inventory

**File**: `problem2.c` | **Lines**: 197 | **Architecture**: Sequential Pipeline

A streamlined product price management system with automatic processing flow.

#### Key Features
- ✅ Linear sequential execution
- ✅ Single array architecture
- ✅ Linear search algorithm (O(n))
- ✅ Descending sort implementation
- ✅ Min/Max price analysis
- ✅ Automated workflow

#### Functions
```c
void sortPrices(float prices[], int n)         // Bubble sort descending
int findPrice(float prices[], int n, float target)  // Linear search
float findMax(float prices[], int n)           // Find highest price
float findMin(float prices[], int n)           // Find lowest price
void displayPrices(float prices[], int n)      // Display all prices
```

#### Usage Flow
```
Input Phase
  → Enter number of products
  → Enter each product price
  
Display Phase
  → Show original prices
  
Analysis Phase
  → Display most expensive product
  → Display least expensive product
  
Sort Phase
  → Sort prices (descending)
  → Display sorted prices
  
Search Phase
  → Search for specific price
  → Show result (position/not found)
```

---

## 🔄 Features Comparison

| Feature | Problem 1 (Grades) | Problem 2 (Prices) |
|---------|-------------------|-------------------|
| **Execution Model** | Interactive menu loop | Linear sequential |
| **Data Type** | Integer (int) | Float (float) |
| **Array Strategy** | Dual arrays | Single array |
| **Sort Algorithm** | Bubble sort | Bubble sort |
| **Sort Direction** | Ascending | Descending |
| **Search Algorithm** | Binary search O(log n) | Linear search O(n) |
| **Search Requirement** | Must sort first | Works on any data |
| **State Management** | Global flags | Local variables |
| **Data Preservation** | Original preserved | Original overwritten |
| **User Control** | High (menu-driven) | Low (automated) |
| **Additional Features** | Before/after view | Min/Max analysis |

---

## 🚀 Installation

### Prerequisites
- Embarcadero Dev-C++ (or any C compiler)
- Terminal/Command Prompt
- Basic C programming knowledge

---

## 📖 Usage

### Example: Grade Management System

```
=== Choose menu here ===
1. input or change array
2. shorting the grade now
3. searching the grade
4. displaying grade before and after shorting
5. exit
Choose: 1

input how much grades did you want to input: 5
Enter grade 1 (0 - 100): 85
Enter grade 2 (0 - 100): 92
Enter grade 3 (0 - 100): 78
Enter grade 4 (0 - 100): 95
Enter grade 5 (0 - 100): 88

Choose: 2
[Grades sorted]

Choose: 3
Enter number to search: 92
===========================
your grades are in index: 3
and in the position: 4
===========================

Choose: 4
These are your grade before:
85 92 78 95 88

here's your grades after:
78 85 88 92 95
```

### Example: Product Price Inventory

```
=== Product Prices Inventory ===
Enter number of products: 4
Enter price for product 1: 25.50
Enter price for product 2: 42.00
Enter price for product 3: 15.99
Enter price for product 4: 33.25

==== Original Prices ====
Product 1: 25.50
Product 2: 42.00
Product 3: 15.99
Product 4: 33.25

Most expensive product: 42.00
Least expensive product: 15.99

==== Sorting Prices Descending ====
Prices sorted successfully!

==== Sorted Prices Descending ====
Product 1: 42.00
Product 2: 33.25
Product 3: 25.50
Product 4: 15.99

==== Search for a Price ====
Enter price to search: 33.25
Price 33.25 found at position 2 (index 1).
```

---

## 🔧 Technical Details

### Algorithms Implementation

#### Bubble Sort (Both Programs)
```c
// Ascending (Problem 1)
for (i = 1; i < n; i++)
    for (j = 0; j < n - 1; j++)
        if (a[j] > a[j + 1])
            swap(a[j], a[j+1]);

// Descending (Problem 2)
for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - 1 - i; j++)
        if (prices[j] < prices[j + 1])
            swap(prices[j], prices[j+1]);
```

#### Binary Search (Problem 1)
```c
int low = 0, high = n-1;
while(low <= high) {
    int mid = (low+high)/2;
    if(a[mid] == value) return mid;
    else if(a[mid] < value) low = mid + 1;
    else high = mid - 1;
}
```

#### Linear Search (Problem 2)
```c
for (i = 0; i < n; i++)
    if (prices[i] == target)
        return i;
return -1;
```

### Input Validation

**Problem 1**: Range validation (0-100) with re-prompt
```c
while (scanf("%d", &arr[i]) != 1 || arr[i] < 0 || arr[i] > 100) {
    printf("Invalid! Enter a number between 0 - 100: \n");
}
```

**Problem 2**: Positive value validation with counter trick
```c
if (prices[i] <= 0) {
    printf("Price must be positive. Try again.\n");
    i--; // Force loop retry
}
```

### State Management (Problem 1)

```c
int flag = 0;   // Input state (0=no data, 1=has data)
int flag2 = 0;  // Sort state (0=unsorted, 1=sorted)
int counter = 1; // Loop controller
```

Operation guards ensure correct execution order:
- **Search**: Requires `flag != 0` AND `flag2 != 0`
- **Before/After**: Requires `flag != 0` AND `flag2 == 1`

---

## 👥 Team

<div align="center">

| Name | GitHub | Role |
|------|--------|------|
| Muhammad Ghiffari | [@muhammadghiffari](https://github.com/muhammadghiffari) | Developer |
| Fhutka Hiban Dairoby | [@hicesse](https://github.com/hicesse) | Developer |

</div>

---

## 📝 Assignment Context

**Course**: Programming Concepts  
**Assignment**: Assignment 4 - Array Operations  
**Problems Selected**: Problem 1 (Grade Management) & Problem 2 (Price Inventory)  
**Language**: C Programming

### Learning Objectives Achieved
✅ Array declaration and manipulation  
✅ Function modularization and parameter passing  
✅ Sorting algorithm implementation (Bubble Sort)  
✅ Search algorithm implementation (Binary & Linear)  
✅ Input validation and error handling  
✅ State management and control flow  
✅ User interface design (menu-driven & sequential)

---

## 📄 License

This project is created for educational purposes as part of academic coursework.

---

<div align="center">

**Made with 💻 for Programming Concepts Subject**

[![Made with C](https://img.shields.io/badge/Made%20with-C-00599C?style=flat-square&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))

</div>
