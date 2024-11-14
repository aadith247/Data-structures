
# DATA-STRUCTURES
## Data structures Using C language
> This repository contains beginner-friendly C programs that cover fundamental data structures, designed to be simple and easy to understand.

## Contents:

- **Arrays**: Basic operations, including insertion, deletion, and traversal, with examples.
- **Linked Lists**: Implementation of singly, doubly, and circular linked lists with common operations.
- **Stacks**: Introduction to stack data structure with push, pop, and peek operations, using both arrays and linked lists.
- **Queues**: Explanation of standard, circular, and priority queues with enqueue and dequeue operations.
- **Trees**: Overview of binary trees, binary search trees, and traversal methods (in-order, pre-order, post-order).
- **Graphs**: Introduction to graph data structures, including:
  - **Graph Representation**: Adjacency matrix and adjacency list.
  - **Graph Traversals**: Depth-First Search (DFS) and Breadth-First Search (BFS).
  - **Minimum Spanning Tree**: Algorithms like Kruskal’s and Prim’s.
  - **Shortest Path**: Dijkstra’s algorithm.
  - **Maximum Flow**: Ford-Fulkerson algorithm.

## Algorithms and their Descriptions:

- **Dijkstra’s Algorithm**: 
  - **Description**: This algorithm finds the shortest path from a source node to all other nodes in a weighted graph with non-negative edge weights. It is based on the greedy approach and uses a priority queue to choose the node with the smallest tentative distance at each step.
  
- **Kruskal’s Algorithm**: 
  - **Description**: Kruskal’s algorithm is used to find the Minimum Spanning Tree (MST) of a graph. It works by sorting the edges of the graph by weight and adding them one by one to the MST, provided they don’t form a cycle.

- **Prim’s Algorithm**: 
  - **Description**: Prim’s algorithm is another algorithm for finding the Minimum Spanning Tree (MST). Unlike Kruskal’s, it starts with an arbitrary node and grows the MST by adding the smallest edge that connects a node inside the MST to one outside it.

- **Ford-Fulkerson Algorithm**: 
  - **Description**: This algorithm is used to compute the maximum flow in a flow network. It uses augmenting paths to push flow through the network until no more augmenting paths can be found. The algorithm’s efficiency can be improved using the Edmonds-Karp approach, which implements BFS for finding augmenting paths.

Each section includes well-documented code examples and explanations to help beginners grasp key concepts in data structures and algorithms.

**sorting**

## Bucket Sort
Explaination-Bucket sort divides data into several groups, or "buckets," based on value ranges. Each bucket is sorted individually and then combined for the final result. It works best when data is uniformly distributed.

## Radix Sort
Explaination-Radix sort sorts numbers by processing each digit, starting from the least significant to the most significant. This approach is efficient for fixed-length integers and can achieve linear time complexity.

## Counting Sort-
Explaination-Counting sort works by counting occurrences of each unique element in the data, then using these counts to determine each element's position in the sorted output. It is efficient for small ranges of integers and works in linear time but requires extra space for counting arrays.

**Linked list operations**

## FindLoops in Linked List:
This program detects the presence of a cycle (loop) in a singly linked list using Floyd’s Cycle Detection Algorithm, also known as the "Tortoise and Hare" method. The algorithm uses two pointers:

## The slow pointer (tortoise) moves one node at a time.
The fast pointer (hare) moves two nodes at a time. If a loop exists, these pointers will eventually meet at some point in the list. This approach is efficient with a time complexity of O(n) and a space complexity of O(1).
Palindrome Check in Linked List:
This program checks whether the elements of a linked list form a palindrome (the sequence reads the same forwards and backwards).


