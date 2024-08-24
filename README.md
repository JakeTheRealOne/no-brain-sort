# No brain sort - stop using your brain
## Disclaimer
This algorithm is non-conventional. Apologies in advance.
## Explanation
#### Steps of sorting:
1. Seperate the negative and positive integers in the vector -> $\Theta(1)$
2. Get the minimum number of bits used to store any integer in the vector
3. Recursion (i = current bit to treat)
    - Split the vector in two sublists (INT[i] == 0 or 1)
    - Call the function with the next bit and do the same with the current sublist
#### Visualize recursivity:
Let's take for example this vector of integers:

The binary representation of this list is:
![step0](https://github.com/JakeTheRealOne/no-brain-sort/blob/master/assets/step0.png)
We split the integers comparing the first bit of each integer. We get in the first sublist 5, 2, 6 and in the second 8:
![step1](https://github.com/JakeTheRealOne/no-brain-sort/blob/master/assets/step1.png)
We do the same for the second bit and the two sublists, now the vector is separated in 3 sublists: [2], [6, 5] and [8]:
![step2](https://github.com/JakeTheRealOne/no-brain-sort/blob/master/assets/step2.png)
finally, we finish the job with the third bit (the fourth bit is not used here since each sublist consist of a single integer):
![step3](https://github.com/JakeTheRealOne/no-brain-sort/blob/master/assets/step3.png)
Here you go! A perfectly sorted vector:
## Benefits
- in place
- stable
- the lower and the higher the list, the faster this algorithm will be
## Time complexity
Best case: $$\Theta(n)$$
Average case: $$\Theta(n)$$
Worst case: $$\Theta(n)$$
## Memory complexity
$$\Theta(1)$$
There is indeed space used for the recursion. This should be $\Theta(logm)$ where m is the number of bits used to represent all the integers in the vector. We round up this complexity to $\Theta(1)$ since m is constant (e.g. max 32 bits for C++ int).