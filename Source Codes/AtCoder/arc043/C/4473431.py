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


if __name__ == "__main__":
    N = int(input())
    A = list(map(lambda x: int(x)-1, input().split()))
    B = list(map(lambda x: int(x)-1, input().split()))

    d = dict((j, i) for i, j in enumerate(A))
    for i, n in enumerate(B):
        B[i] = d[n]

    inv_list = [0]*N
    bit = BinaryIndexedTree(N)
    for i, n in enumerate(B):
        inv_list[n] = i - bit.sum(n+1)
        bit.add(n+1, 1)

    inv_count = sum(inv_list)
    if inv_count % 2:
        print(-1)
        exit()

    inv_count //= 2
    ans = []
    for i, n in enumerate(inv_list):
        if n <= inv_count:
            inv_count -= n
            inv_list[i] = -1
            ans.append(i)
    for n in B:
        if inv_list[n] >= 0:
            ans.append(n)

    i = 0
    while inv_count:
        j = i+1
        while j > 0 and inv_count:
            if ans[j-1] < ans[j]:
                break
            ans[j-1], ans[j] = ans[j], ans[j-1]
            j -= 1
            inv_count -= 1
        i += 1

    d = dict((j, i) for i, j in d.items())
    for i, n in enumerate(ans):
        ans[i] = d[n]+1

    print(*ans)