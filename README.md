# No brain sort - stop using your brain
## Explanation
#### Sorting steps:
1. Seperate the negative and positive integers in the vector.
2. Get the minimum number of bits used to store any integer in the vector.
3. Recursion (i = current bit to treat)
    - Split the vector in two sublists (INT[i] == 0 or 1)
    - Call the function with the next bit and do the same with the current sublist
#### Visualize recursivity:
Let's take for example this vector of integers:\
<img src="https://github.com/JakeTheRealOne/no-brain-sort/blob/master/assets/begin.png" alt="begin" width="300"/>

Its binary representation is:\
<img src="https://github.com/JakeTheRealOne/no-brain-sort/blob/master/assets/step0.png" alt="step0" width="300"/>

We split the integers comparing the first bit of each integer. We get in the first sublist 5, 2, 6 and in the second 8:\
<img src="https://github.com/JakeTheRealOne/no-brain-sort/blob/master/assets/step1.png" alt="step1" width="300"/>

We do the same for the second bit and the two sublists, now the vector is separated in 3 sublists: [[2], [6, 5]] and [8]:\
<img src="https://github.com/JakeTheRealOne/no-brain-sort/blob/master/assets/step2.png" alt="step2" width="300"/>

finally, we finish the job with the third bit (the fourth bit is not used here but could be if there was still a sublist of size > 1):\
<img src="https://github.com/JakeTheRealOne/no-brain-sort/blob/master/assets/step3.png" alt="step3" width="300"/>

Here yah go! A perfectly sorted vector:\
<img src="https://github.com/JakeTheRealOne/no-brain-sort/blob/master/assets/end.png" alt="end" width="300"/>

## Benefits
- in place
- stable
## Complexity
n := Number of elements of the list.

m := Number of bits of the maximum of the list.

#### Time:
$$\Theta(n \times m) \approx \Theta(n)$$

#### Space:
$$\Theta(\log(m)) \approx \Theta(1)$$
