
class Solution:
    def sortedSquares(self, nums):
        a = []
        b = []

        n = len(nums)

        # Separate negative and positive numbers
        for i in range(n):
            if nums[i] >= 0:
                a.append(nums[i])
            else:
                b.append(nums[i])

        # Square positive numbers
        for i in range(len(a)):
            a[i] = a[i] * a[i]

        # Square negative numbers
        for i in range(len(b)):
            b[i] = b[i] * b[i]

        # Reverse because squared negative numbers are descending
        b.reverse()

        m = len(a)
        k = len(b)

        i = 0
        j = 0
        id = 0

        res = [0] * (m + k)

        # Merge
        while i < m and j < k:
            if a[i] <= b[j]:
                res[id] = a[i]
                i += 1
            else:
                res[id] = b[j]
                j += 1
            id += 1

        # Remaining b
        while j < k:
            res[id] = b[j]
            j += 1
            id += 1

        # Remaining a
        while i < m:
            res[id] = a[i]
            i += 1
            id += 1

        return res
