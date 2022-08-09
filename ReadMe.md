# Algorithms And Data Structures

> **Abstract Data Types** or ADTs is a mathematical model for datatypes. In more programming terms, ADTs mention only the operations that can be perfromed but not how the operation will be implemented. For example A List ADT can be implemented as an Array List or as a Linked List.

> **Data Structures** are ways in which data can be stored and orgainized in the computer so that it can be efficiently used.

> **Algorithm** can be defined as unambiguous step by step instruction to solve a problem.

Comparing Algorithms :

As the execution time of any algorithm on different systems can differ greatly we do not measure the absolute time of function execution.

So we use non system dependent parameters to measure the time complexity of a problem. For example we consider the input size for an algorithm and how it would effect the running time of that algorithm.

**Rate of Growth** is the rate at which the running time increases as a function of the input size.

## Data Structures and Algorithms implementation in C++.

> The Included `.vscode` has build and run tasks, and launch configuration for MinGW C++ compiler.
> For the task to work, the bin folder for the compiler must be added to the class path.

## Recursion

General Format of Recursion.

```cpp
if(testForBaseCase)
    return someBaseCaseValue;
else if(testForAnotherBaseCase)
    return someOtherBaseCaseValue;
else
    return someWorkAndThenARecurssionCall
```

We take a simple example of calculating factorial with recursion.

```cpp
//calculate factorial for a given number +ve number.
int factorial(int num)
{
  if(num <= 1) return 1; //base case

  //do work with returned value from recursion
  else return num*factorial(num-1); //recursive cases
}
```

We can optimize the above example and most recursion problems with memoization.

> **Memoization** ensures that a method doesn't run for the same inputs more than once by keeping a record of the results for the given inputs.

Advantages and Disadvantages of Recursion :

1. Solution to problem are easier to formulate recursion.
2. It adds overhead to the program. Unlike loops, recursion uses additional memory on the stack for each call of recursive function.
3. If there are too many recursive calls, it might lead to stack overflow.

## Priority Queues

Each element has a certain priority. Elements that have higher prority come out first. 

All elements should be comparable to use prority queues.

It uses a heap( A tree that satisfies the heaping variant ).

Uses of Priority queue :

1. Dijkstra's Shortest Path algorithms.
2. Next best, next worst element.
3. Huffman Coding.
4. Best first search.
5. Minimal Spanning tree.

### Turn max PQ to min PQ

We can negate the comparator to get convert between max and min priority queue.

