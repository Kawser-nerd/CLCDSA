class BinaryIndexedTree(object):
    __slots__ = ["tree", "size"]

    def __init__(self, size: int):
        self.tree = [0]*(size+1)
        self.size = size+1

    def add(self, index: int, value: int):
        tree = self.tree

        while index < len(tree):
            tree[index] += value
            index += index & -index

    def sum(self, index: int):
        tree, result = self.tree, 0

        while index:
            result += tree[index]
            index -= index & -index

        return result

    def lower_bound(self, value: int):
        size, tree = self.size, self.tree
        index, result = 2**(size.bit_length()-1), 0

        while index:
            if result + index < size and tree[index+result] < value:
                value -= tree[index+result]
                result += index
            index >>= 1

        return result+1


if __name__ == "__main__":
    N, K = map(int, input().split())

    bit = BinaryIndexedTree(N+1)
    add, sum, lower_bound = bit.add, bit.sum, bit.lower_bound
    p = 1
    availvable = [1]*N
    result = []

    for i in range(N, 0, -1):
        add(i, 1)
        n = i*p//K
        result.append(n)
        p = i*p % K

    for i in range(N-1, -1, -1):
        if result[i]:
            result[i] -= 1
            break
        result[i] = N-1-i

    for i, n in enumerate(result):
        j = lower_bound(n+1)
        add(j, -1)
        result[i] = j

    print(*result, sep="\n")