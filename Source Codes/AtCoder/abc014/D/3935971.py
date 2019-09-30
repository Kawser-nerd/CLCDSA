class SegmentTree(object):
    __slots__ = ["elem_size", "tree", "default", "op"]

    def __init__(self, a: list, default: int, op):
        from math import ceil, log
        real_size = len(a)
        self.elem_size = elem_size = 1 << ceil(log(real_size, 2))
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


def euler_tour(edges):
    from collections import deque

    tree_size, euler_tour_size = len(edges), len(edges)*2-1

    tree = [0]*tree_size
    vertices = [-1]*tree_size
    tree_depth = [0]*euler_tour_size
    dq, index = deque([(0, 1)]), -1
    pop, append, extend = dq.pop, dq.append, dq.extend

    while index < euler_tour_size-1:
        index, (v, depth) = index+1, pop()
        tree_depth[index] = depth
        if vertices[v] > -1:
            continue

        vertices[v] = index
        append((tree[v], depth-1))
        for dest in edges[v]:
            if dest != tree[v]:
                append((dest, depth+1))
                tree[dest] = v

    return tree_depth, vertices


if __name__ == "__main__":
    import sys
    N = int(input())
    edges = [[] for _ in [0]*N]
    for x, y in ((map(int, sys.stdin.readline().split())) for _ in [0]*(N-1)):
        edges[x-1].append(y-1)
        edges[y-1].append(x-1)

    tree_depth, vertices = euler_tour(edges)
    segment_tree = SegmentTree(tree_depth, 10**9, min)
    input()
    for a, b in (map(int, l.split()) for l in sys.stdin):
        left, right = vertices[a-1], vertices[b-1]
        if left > right:
            left, right = right, left

        d = segment_tree.get_value(left, right+1)
        print(tree_depth[left]+tree_depth[right]-2*d+1)