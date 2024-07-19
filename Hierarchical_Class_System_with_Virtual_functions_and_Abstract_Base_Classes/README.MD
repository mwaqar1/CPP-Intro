# Project: Hierarchical Class System with Virtual Functions and Abstract Base Classes in C++

## Description

Developed a comprehensive hierarchy of C++ classes to explore and demonstrate the application of virtual functions and abstract base classes. This project involved designing and implementing a system of four distinct classes:

1. **Shape**: 
   - An interface (abstract base class) encapsulating a drawable shape on the screen.
   - Features pure virtual functions for `draw` and `getSpecs`, and a virtual destructor to ensure proper memory management for derived classes.

2. **LblShape**: 
   - An abstract base class derived from `Shape`, representing shapes with labels.
   - Implemented the `getSpecs` function while leaving `draw` as a pure virtual function.
   - Managed dynamic memory for a character pointer member variable `m_label` to store labels.

3. **Line**: 
   - A concrete class inheriting from `LblShape`, designed to draw labeled horizontal lines.
   - Implemented constructors for initialization, the `getSpecs` function to handle input, and the `draw` function to render the labeled line on the screen.

4. **Rectangle**: 
   - A concrete class also inheriting from `LblShape`, designed to draw labeled rectangles.
   - Implemented constructors for initialization, the `getSpecs` function to handle input, and the `draw` function to render the labeled rectangle on the screen.

## Learning Outcomes

- Defined and utilized pure virtual functions in an abstract base class.
- Created and worked with abstract base classes and concrete classes.
- Implemented behavior using virtual functions to achieve polymorphism.
- Distinguished between abstract base classes and concrete classes.
- Managed dynamic memory allocation and deallocation effectively.
- Applied object-oriented principles to develop a reusable and extendable class hierarchy.

## Key Skills

- Object-Oriented Programming (OOP)
- Virtual Functions and Polymorphism
- Abstract Base Classes
- Dynamic Memory Management
- C++ Inheritance and Class Design
- Operator Overloading
- Stream Input/Output Handling

## Technical Implementation

### Shape

- Defined pure virtual functions `draw(void, receiving ostream&)` and `getSpecs(void, receiving istream&)`.
- Created a virtual destructor to ensure proper memory management for derived classes.

### LblShape

- Added a private character pointer `m_label` for dynamic label storage.
- Implemented `getSpecs` to read comma-delimited strings.
- Provided constructors and a destructor for memory management.

### Line

- Introduced a private integer `m_length` for line length.
- Implemented constructors for initialization.
- Overrode `getSpecs` to handle input for line length.
- Overrode `draw` to render the labeled line.

### Rectangle

- Added private integers `m_width` and `m_height` for dimensions.
- Implemented constructors for initialization.
- Overrode `getSpecs` to handle input for dimensions.
- Overrode `draw` to render the labeled rectangle.

Successfully completed the workshop by implementing all required classes and functions, demonstrating a thorough understanding of virtual functions, abstract base classes, and inheritance in C++.
