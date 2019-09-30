class BIT:
    def __init__(self, size: int):
        self.__size = size
        self.__data = [0] * (size + 1)

    def update(self, idx: int, v: int):
        while idx <= self.__size:
            self.__data[idx] += v
            idx += idx & -idx

    def sum(self, l: int, r: int):
        """(l, r] ????
        """
        return self.__sum(r) - self.__sum(l)

    def __sum(self, idx: int):
        s = 0
        while idx > 0:
            s += self.__data[idx]
            idx -= idx & -idx
        return s


def practical_skill_test(
        H: int, W: int, D: int, A: list, Q: int, queries: list) -> list:
    # sorted_A = sorted([(A[h][w], h, w) for h in range(H) for w in range(W)])
    per_rem = [[] for _ in range(D)]
    for h in range(H):
        for w in range(W):
            a = A[h][w]
            per_rem[a % D].append((a, h, w))

    # ?????????
    ss = []
    for d in range(D):
        per_rem[d].sort()

        n = len(per_rem[d])
        ss.append([0] * (n + 1))

        for idx in range(n-1):
            _, i, j = per_rem[d][idx]
            _, x, y = per_rem[d][idx + 1]
            # print('{}({},{}) -> {}({},{})'.format(a, i, j, b, x, y))

            ss[d][idx + 1] = ss[d][idx] + abs(x - i) + abs(y - j)

    res = []
    for l, r in queries:
        d = l % D
        if d > 0:
            li, ri = l // D, r // D
        else:
            li, ri = l // D - 1, r // D - 1
        res.append(ss[d][ri] - ss[d][li])

    return res


if __name__ == "__main__":
    H = 0
    H, W, D = map(int, input().split())
    A = [list(map(int, input().split())) for _ in range(H)]
    Q = int(input())
    queries = [tuple(int(s) for s in input().split()) for _ in range(Q)]

    ans = practical_skill_test(H, W, D, A, Q, queries)
    for a in ans:
        print(a)