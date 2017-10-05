Project 0: Dynamic Memory Manager

Group:
Jonathan Ma - dm269
Jason Wang - jsw50
Hong Niu - hn36

Time spent: 10 hours

We initially attempted an explicit approach, but ran into multiple difficulties,
especially with pointer arithmetic spending a couple days trying to debug dfree.
We later decided to completely switch our design over to an implicit approach,
using a list that includes both free and not free blocks, adding a Boolean variable
to keep track of whether or not each block was free and checking coalesce each
time dfree was called. In the end we were able to finish not too long after switching
implementations. Throughout the process we ran through the basic tests, many of
our own written tests, the stress tests from piazza and finally the autograder and
in the end with the new implementation were able to pass all of them.

Our implementation does allow for a dfree and coalesce of O(1) time, but will
cause dmalloc to run a bit slower, since we must iterate through each block
to determine if it is free and whether it suffices the input size. The header
metadata also takes up extra space, so there will likely be more dmalloc failures
since a good amount of the space will be used to store the metadata.

No outside sources were used apart from group members and class notes/lectures.
