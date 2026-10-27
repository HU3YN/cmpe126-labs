# Lab 4: linked lists and the Faro shuffle

A templated `LinkedList<T>` with a copy constructor, append and equality. A 52-card deck is shuffled by splitting it in half and merging the halves as an in-shuffle or an out-shuffle. A loop counts the shuffles until the deck returns to its original order and writes each shuffle to a file.

Result: out-shuffles restore the deck in 8 shuffles and in-shuffles take 52.

AI gave hints on the merge, shuffle and counting helpers while I worked out the logic and wrote the code.

`card.h` (the Card, Suit and Rank types) was provided by the course for this lab. I wrote the rest.
