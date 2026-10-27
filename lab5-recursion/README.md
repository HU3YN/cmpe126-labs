# Lab 5: recursion

- Recursive factorial, sorted-check and string reverse.
- Naive Fibonacci with call counting: for n=39 it made 204,668,309 calls, which is exponential, O(2^n).
- Memoized Fibonacci with a separate cache vector: 77 calls (2n - 1), O(n) time and O(n) space.
- A linked-list merge sort that finds the middle with a slow and fast pointer and relinks nodes without copying data. All test lists sorted correctly, including empty, one-element, duplicate and 35-element cases.

AI hinted at the separate cache vector and the two-pointer idea, and helped with debugging.
