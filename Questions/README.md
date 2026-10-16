# Theorical questions

[Back to main README](../README.md)

1. What are the steps involved in the compilation process?

The steps are
Preprocessing, it handle #include and #define.
Compilation, turns all scripts into assembly
Assemnly, turns assmebly into object
Linkage, combine object file and library

2. What is the difference between a declaration and a definition?

The declaration doesn't use memory it just warn the compiler that the item declared will be here, the definition on the 
other hand allocate memory and explicit what's the object and how to use it . 

3. What is the difference between passing a parameter by value, by reference, and by pointer?

Passing a parameter by value means it will create a copy how the value it was passed. 
Passing a parameter by reference keep the referenced objet, that means if the variable for example is modified inside the scope of 
the function it will also be modified outside. 
Passing a parameter by pointer means it will copy the memory adress of the value.

4. What is the difference between the stack and the heap?

The stack is a little automatic memory allocated at runtime for when a function is called and freed at the end of the scope.
The heap is bigger dynamic memory allocated that live until it's free.
5. What is the difference between struct and class in C++?

In C++, the difference between struct and class are the base acessiblity. Struct is by default public, class is private.

6. What is the difference between the public, protected, and private access specifiers?

Public means everybody can acess it. 
Protected means only the class itself and inheritors (and friend) can acess it. 
Private means only the class itself (and friend) can access it.

7. What is a pure virtual function? What effect does it have on a class?

A pure virtual function is a function virtual defined with = 0. It makes the class abstract it cannot be instanciated. It makes the class that inherit it override it.

8. Briefly explain the diamond problem in multiple inheritance.

In C++ multiple inheritance is possible. That means that a class can inherit from two class that inherited from the same one.
Example : Status class, both student and worker inherit from status. But human inherit from both student and worker. That means that human inherit twice from status.
The solution is to use the virtual innheritance (public worker : virtual status, public student : virtual status). 

9. Name the different containers studied in class and describe the strengths and weaknesses of each.

10. For each of the following scenarios, identify the most appropriate container and justify your choice.
- You need to store the top ten scores in a game. The number of elements is known and will never change.

Array. The size is known at complilation time.

- You need to manage a queue of tasks that must be executed in the order they arrive.

Queue. It's the better to manage in FIFO (First In First Out)

- You frequently need to insert and remove elements in the middle of a sequence.

List. You need to insert and remove in the middle of the sequence and keep the order.

- You need to store a large number of elements and frequently check whether a particular element exists. The order of the elements does not matter.

unordered_set. The faster to look up a large amount of element.

- You need to keep track of actions so that the most recent action can be undone before earlier actions.

Stack. It's the better to manage in LIFO (Last In First Out)

- You need to manage a collection of players whose number can change over time, with frequent read and traversal operations.

Vector. It's the most flexible non fixedsize array.

- You need to associate each student ID with a grade and retrieve a grade quickly using the student ID.

unorder_map. It's the fastest to searsh a value by an unique id.