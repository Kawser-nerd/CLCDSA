import sys
from bisect import bisect_left
fin = sys.stdin.readline
from math import log, floor, ceil


N = int(fin())
size_list = [[int(elem) for elem in fin().split(' ')] for _ in range(N)]
assert len(size_list) == N
assert len(size_list[0]) == 2

# Imperfect solution
## time complexity: O(N^2)
## space complexity: O(N)
def imperfect_method(size_list):
    size_list.sort(key=lambda x: (x[0], x[1]))
    N = len(size_list)
    dp = [0] * N
    dp[0] = 1
    for i in range(1, N):
        max_dp = 0
        width, height = size_list[i]
        for j in range(i):
            if size_list[j][0] < width and size_list[j][1] < height:
                max_dp = max(max_dp, dp[j])
        dp[i] = max_dp + 1
    return max(dp)

#print(imperfect_method(size_list))


class BaseBinaryIndexedTree(object):
    """
    Implementation of Binary Indexed Tree.
    Each element has to have something corresponding to its range.
    You can inherit this and implement what each element has.
    Note that it is 1-indexed and self._array[0] is a dummy.
    """
    def __init__(self, array, padding_value):
        padded_length = 2 ** ceil(log(len(array), 2))
        self._array = [padding_value for _ in range(padded_length + 1)]
        for i, value in enumerate(array, start=1):
            self._update(i, value)


    def __repr__(self):
        return repr(self._array)


    def _update(self, idx, value):
        """
        update such that a[idx] <operation> value.
        """
        pass
    

    def _query_for_prefix(self, idx):
        """
        query for a[:idx + 1].
        """
        pass


class MaxBIT(BaseBinaryIndexedTree):
    def __init__(self, array):
        super().__init__(array, 0)


    def set(self, idx, value):
        """
        set a[idx] to be value.
        time complexity: O(lgN)
        """
        self._update(idx, value)
    

    def _update(self, idx, value):
        while idx <= len(self._array):
            self._array[idx] = max(self._array[idx], value)
            idx += idx & -idx


    def max(self, idx):
        """
        obtain the maximum value of a[:idx + 1].
        time complexity: O(lgN)
        """
        return self._query_for_prefix(idx)


    def _query_for_prefix(self, idx):
        max_prefix = 0
        while idx > 0:
            max_prefix = max(self._array[idx], max_prefix)
            idx -= idx & -idx
        return max_prefix



# Perfect solution using Binary Indexed Tree
# time complexity: O(NlogN)
# space complexity: O(N)
def perfect_method_w_BIT(size_list):
    N = len(size_list)
    # sort w.r.t. height in ascending order 
    # and secondly w.r.t. weight in descending order
    size_list.sort(key=lambda x: (x[1], -x[0]))
    w_list = [w for w, h in sorted(size_list, key=lambda x: (x[1], -x[0]))]
    max_w = max(w_list)
    bit = MaxBIT([0] * max_w)
    dp = [0] * (N + 1)
    for i, w in enumerate(w_list, start=1):
        # O(logN)
        dp[i] = bit.max(w - 1) + 1
        # O(logN)
        bit.set(w, dp[i])
    return max(dp)


def bit_max(bit_array, idx):
    max_prefix = 0
    while idx > 0:
        max_prefix = max(bit_array[idx], max_prefix)
        idx -= idx & -idx
    return max_prefix


def bit_set(bit_array, idx, value):
    while idx <= len(bit_array):
        bit_array[idx] = max(bit_array[idx], value)
        idx += idx & -idx


# O(NlogN) solution but using an array directly
# space complexity: O(N)
def faster_method_w_BIT(size_list):
    N = len(size_list)
    # sort w.r.t. height in ascending order 
    # and secondly w.r.t. weight in descending order
    w_list = [w for w, h in sorted(size_list, key=lambda x: (x[1], -x[0]))]
    bit = [0] * (10**5 + 1)
    dp = [0] * (N + 1)
    max_dp = 0
    for i, w in enumerate(w_list, start=1):
        dp[i] = bit_max(bit, w - 1) + 1
        max_dp = max(max_dp, dp[i])
        bit_set(bit, w, dp[i])
    return max_dp


def calc_len_LIS(sorted_list):
    tails = [0] * len(sorted_list)
    size = 0
    for x in sorted_list:
        idx = bisect_left(tails, x, lo=0, hi=size)
        tails[idx] = x
        size = max(idx + 1, size)
    return size

# Perfect solution without BIT
# time complexity: O(NlgN)
# space complexity: O(N)
def perfect_method_wo_BIT(size_list):
    # After sorting w.r.t. height in ascending order
    # and secondly w.r.t. weight in descending order,
    # calculating LIS will suffice!
    size_list.sort(key= lambda x: (x[1], -x[0]))
    num_box = calc_len_LIS([w for w, h in size_list])
    return num_box

#print(perfect_method_w_BIT(size_list))
print(faster_method_w_BIT(size_list))