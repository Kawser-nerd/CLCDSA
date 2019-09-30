import math
from heapq import heappush, heappop


class SegmentTree:
    __slots__ = ["elem_size", "tree_size", "tree", "default"]

    def __init__(self, a: list, default: int):
        real_size = len(a)
        self.elem_size = 1 << math.ceil(math.log2(real_size))
        self.tree_size = 2 * self.elem_size
        self.tree = [default] * self.elem_size + a + [default] * (self.elem_size - real_size)
        self.init_tree()
        self.default = default

    def init_tree(self):
        tree = self.tree
        for i in range(self.elem_size - 1, 0, -1):
            left, right = tree[i << 1], tree[(i << 1) + 1]
            tree[i] = left if left < right else right

    def get_value(self, x: int, y: int):
        tree = self.tree
        l, r = x + self.elem_size, y + self.elem_size
        result = self.default
        while l < r:
            if l & 1:
                result = tree[l] if tree[l] < result else result
                l += 1
            if r & 1:
                r -= 1
                result = tree[r] if tree[r] < result else result
            l, r = l >> 1, r >> 1

        return result


N = int(input()) >> 1
p = tuple(map(int, input().split()))

inf = float("inf")
odd_tree = SegmentTree([(n, i) for i, n in enumerate(p[::2])], (inf, 0))
even_tree = SegmentTree([(n, i) for i, n in enumerate(p[1::2])], (inf, 0))
odd_get, even_get = odd_tree.get_value, even_tree.get_value

result = []
append = result.append
queue = [(odd_get(0, N), 0, N, 0)]

while queue:
    x, s, e, add = heappop(queue)
    if add:
        get1, get2 = even_get, odd_get
    else:
        get1, get2 = odd_get, even_get
    y = get2(x[1]+add, e+add)

    append(x[0])
    append(y[0])

    l1, r1 = s, x[1]
    l2, r2 = x[1]+add, y[1]
    l3, r3 = y[1]+1-add, e

    if l1 < r1:
        heappush(queue, (get1(l1, r1), l1, r1, add))
    if l2 != r2:
        heappush(queue, (get2(l2, r2), l2, r2, add^1))
    if l3 < r3:
        heappush(queue, (get1(l3, r3), l3, r3, add))

print(" ".join(map(str, result)))