/**
 * Author: JakeTheRealOne (jakelevrai@outlook.be)
 * Brief: No brain sort - practical sorting algorithm
 * Date: 24-08-2024
 */


import java.util.Arrays;


public class NoBrainSort {
    public static void main(String[] args)
    {
        int[][] testNums = {
            {1, 5, 10, 15, 20, 25},
            {8, 1, 5, 9, 13, 2, 0},
            {-5, -1, 5, 1, 1, 3},
            {0, 0, 0, -1, -5, -3},
            {100000, -1000000, 1, 2, -7}
        };
        for (int[] nums : testNums)
        {
            System.out.print(Arrays.toString(nums) + " -> ");
            sort(nums);
            System.out.print(Arrays.toString(nums) + "\n");
        }
    }

    /**
     * Sort an array of integers (ascending order)
     */
    public static void sort(int[] nums)
    {
        int offset = isolateNegatives(nums);
        {
            int mask = minMask(nums, offset, nums.length);
            arrange(nums, offset, nums.length, mask, false);
        }
        {
            int mask = minMask(nums, 0, offset);
            arrange(nums, 0, offset, mask, true);
        }
        restoreNegatives(nums, offset);
    }

    /**
     * Isolate at the begining of the array the negative integers
     * Return the number of negative integers
     */
    private static int isolateNegatives(int[] nums)
    {
        int bound = 0, n = nums.length, candidate;
        for (int index = 0; index < n; ++ index)
        {
            candidate = nums[index];
            if (candidate < 0)
            {
                nums[index] = nums[bound];
                nums[bound] = -candidate;
                ++ bound;
            }
        }
        return bound;
    }

    /**
     * Get the minimum mask that can read each value of the slice nums[begin:end]
     */
    private static int minMask(int[] nums, int begin, int end)
    {
        // Get the maximum of the slice nums.from(begin).to(end)
        int maximum = 0, candidate;
        for (int index = begin; index < end; ++ index)
        {
            candidate = nums[index];
            if (candidate > maximum)
            {
                maximum = candidate;
            }
        }
        // Get the minimum mask based on the number of bits of the maximum
        int mask = 1;
        maximum >>= 1;
        while (maximum != 0)
        {
            maximum >>= 1;
            mask <<= 1;
        }

        return mask;
    }

    /**
     * Arrange recursively the slice nums[begin:end] using the ith mask
     */
    private static void arrange(int[] nums, int begin, int end, int mask, boolean reverse)
    {
        if (begin == end || mask == 0)
        {
            return;
        }
        int bound = begin, tmp;
        for (int index = begin; index < end; ++ index)
        {
            if (reverse ? (nums[index] & mask) != 0 : (nums[index] & mask) == 0)
            {
                tmp = nums[index];
                nums[index] = nums[bound];
                nums[bound] = tmp;
                ++ bound;
            }
        }
        mask >>= 1;
        arrange(nums, begin, bound, mask, reverse);
        arrange(nums, bound, end, mask, reverse);
    }

    /**
     * Restore the negative integers of nums after the sorting
     */
    private static void restoreNegatives(int[] nums, int size)
    {
        for (int index = 0; index < size; ++ index)
        {
            nums[index] *= -1;
        }
    }
}
