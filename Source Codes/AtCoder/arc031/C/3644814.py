import math

class SegmentTree(object):
    __slots__ = ["elem_size", "tree", "default", "op"]

    def __init__(self, a: list, default: int, op):
        real_size = len(a)
        self.elem_size = elem_size = 1 << math.ceil(math.log2(real_size))
        self.tree = tree = [default] * (elem_size * 2)
        tree[elem_size:elem_size+real_size] = a
        self.default = default
        self.op = op

        for i in range(elem_size - 1, 0, -1):
            tree[i] = op(tree[i << 1], tree[(i << 1)+1])

    def get_value(self, x: int, y: int) -> int:
        l, r = x + self.elem_size, y + self.elem_size
        tree, result, op = self.tree, self.default, self.op
        while l < r:
            if l & 1:
                result = op(tree[l], result)
                l += 1
            if r & 1:
                r -= 1
                result = op(tree[r], result)
            l, r = l >> 1, r >> 1

        return result

    def set_value(self, i: int, value: int) -> None:
        k = self.elem_size + i
        self.tree[k] = value
        self.update(k)

    def update(self, i: int) -> None:
        op, tree = self.op, self.tree
        while i > 1:
            i >>= 1
            tree[i] = op(tree[i << 1], tree[(i << 1) + 1])


if __name__ == "__main__":
    from operator import itemgetter, add
    N = int(input())
    segtree = SegmentTree([1]*N, 0, add)
    ans = 0
    for i, _ in sorted(enumerate(map(int, input().split())), key=itemgetter(1)):
        segtree.set_value(i, 0)
        ans += min(segtree.get_value(0, i), segtree.get_value(i, N))

    print(ans)