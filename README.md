# dynamic-c-arrays
Implementation of a simple dynamic array in C++ using C-style arrays, mimicking basic functionality of std::vector with dynamic resizing

## Task 1: Check c file.

## Task 2:
Given a dynamic table that doubles in size when it needs more space, find the amoritized runtime for inserting n elements.
a) use the aggregate method
b) use the accounting method


### Part (a): Aggregate Method

In the aggregate method, we calculate the total cost of all insertions and then divide it by the number of insertions to get the amortized cost per insertion.

1. **Total Cost Analysis**:
   - Suppose the initial capacity of the array is \( 1 \), and every time the array reaches its capacity, it doubles.
   - For each element that doesn't trigger a resize, the cost is \( 1 \) (just placing the element in the next available spot).
   - Whenever the array doubles, the cost of resizing is equal to the number of elements currently in the array, as all elements need to be copied to the new array.
   
2. **Cost Breakdown**:
   - When we insert elements, we double the array's size at \( 1, 2, 4, 8, \ldots \) elements.
   - At each doubling, we pay a cost proportional to the current size of the array.
   
3. **Total Cost Calculation**:
   - The total cost \( T(n) \) for \( n \) insertions is the sum of all individual insertions, including the cost of resizing.
   - When the array is resized to size \( 2^k \), the cost of copying elements is \( 2^k \).
   - The series of resize costs for \( n \) elements (until the array reaches size \( n \)) is:
     \[
     T(n) = n + (1 + 2 + 4 + 8 + \ldots + n/2)
     \]
   - The sum of the series \( 1 + 2 + 4 + \ldots + n/2 \) is \( n - 1 \).
   - So, the total cost \( T(n) \) becomes:
     \[
     T(n) = n + (n - 1) = 2n - 1
     \]

4. **Amortized Cost**:
   - The amortized cost per insertion is:
     \[
     \frac{T(n)}{n} = \frac{2n - 1}{n} = 2 - \frac{1}{n}
     \]
   - As \( n \) grows large, the amortized cost approaches \( 2 \).

Thus, **the amortized cost per insertion is \( O(2) = O(1) \)** using the aggregate method.

---

### Part (b): Accounting Method

In the accounting method, we assign an "amortized cost" (or "credit") to each insertion so that the total cost, including resizing, is covered by the amortized costs.

1. **Assigning Amortized Costs**:
   - We assign an amortized cost of \( 3 \) to each insertion.
   - For each insertion that doesn’t cause a resize, we use \( 1 \) of the assigned \( 3 \) credits to perform the insertion and save the remaining \( 2 \) credits as "extra credits."
   
2. **Using Extra Credits for Resizing**:
   - When the array doubles in size, we need to copy all existing elements to the new array.
   - For example, after \( 2^k \) insertions, we double the array from size \( 2^k \) to \( 2^{k+1} \), requiring \( 2^k \) moves.
   - However, with our amortized cost of \( 3 \) per insertion, we save \( 2 \) credits per insertion.
   - By the time the array needs to be resized, we have accumulated enough credits to cover the cost of copying:
     - After \( 2^k \) insertions, we have \( 2 \times 2^k = 2^{k+1} \) credits, which is exactly enough to pay for copying \( 2^k \) elements.

3. **Amortized Cost**:
   - Since each insertion is charged \( 3 \) units, and this amount covers both the insertion and the potential resizing costs, the amortized cost per insertion is \( 3 \), or \( O(1) \).

Thus, **the amortized cost per insertion is \( O(1) \)** using the accounting method.
