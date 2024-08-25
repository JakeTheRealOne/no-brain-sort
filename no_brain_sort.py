"""
Author: JakeTheRealOne
Date: 25-08-2024
Brief: No brain sort - practical sorting algorithm
"""


class NoBrainSort:
    def __init__(self, nums: list[int]):
        """
        ARG:
            - nums: The list of integers to sort
        """
        self._data = nums
        self._mask = 0

    def sort(self) -> None:
        """
        Sort the list of integers
        """
        n = len(self._data)
        offset = self.isolate_neg()

        # Positive integers:
        self._mask = self.compute_mask(offset, n)
        self.arrange(offset, n)

        # Negative integers:
        self._mask = self.compute_mask(0, offset)
        self.arrange(0, offset, True)
        self.restore_neg(0, offset)

    def isolate_neg(self) -> int:
        """
        Isolate the negative integers of data at its beginning
        Return the number of negative integers
        """
        bound = 0
        n = len(self._data)
        for index in range(n):
            candidate = self._data[index]
            if candidate < 0:
                self._data[index] *= -1  # Polish value
                self.swap(bound, index)
                bound += 1

        return bound

    def compute_mask(self, front: int, end: int) -> int:
        """
        Compute and return the minimum mask of data[front:end]
        ARGS:
            - front: The index of the first int of the sublist
            - end: The index of the upper bound of the sublist
        """
        maximum = 0
        for index in range(front, end):
            candidate = self._data[index]
            if candidate > maximum:
                maximum = candidate
        
        mask = 1
        maximum >>= 1
        while maximum:
            mask <<= 1
            maximum >>= 1
        
        return mask

    def arrange(self, front: int, end: int, reverse: bool = False) -> None:
        """
        Arrange recursively the integers in data[front:end]
        ARGS:
            - front: The index of the first int of the sublist
            - end: The index of the upper bound of the sublist
            - reverse: The flag that indicates if we should sort
            the sublist in ascending (0) or descending (1) order
        """
        if not self._mask or front == end:
            return
        
        bound = front
        for index in range(front, end):
            candidate = self._data[index]
            signature = candidate & self._mask
            if signature if reverse else not signature:
                self.swap(bound, index)
                bound += 1

        old_mask = self._mask
        self._mask >>= 1
        self.arrange(front, bound, reverse)
        self.arrange(bound, end, reverse)
        self._mask = old_mask

    def restore_neg(self, front: int, end: int) -> None:
        """
        Restore the negative integers of the data
        ARGS:
            - front: The index of the first int of the negative integers
            - end: The index of the upper bound of the negative integers
        """
        for index in range(front, end):
            self._data[index] *= -1

    def swap(self, index1: int, index2: int) -> None:
        """
        Swap two values in the list of integers
        ARGS:
            index1: The index of the first value to swap
            index2: The index of the second value to swap
        """
        self._data[index1], self._data[index2] = self._data[index2], self._data[index1]


def showcase() -> None:
    """
    Show the result of the No brain sort on a few examples
    """
    test_nums = [
        [1, 5, 10, 15, 20, 25],
        [8, 1, 5, 9, 13, 2, 0],
        [-5, -1, 5, 1, 1, 3],
        [0, 0, 0, -1, -5, -3]
    ]
    for nums in test_nums:
        print(nums, end=" ")
        NoBrainSort(nums).sort()
        print("->", nums)


if __name__ == "__main__":
    showcase()