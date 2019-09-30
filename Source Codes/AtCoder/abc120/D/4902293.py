class uf:

    def __init__(self, n):
        self.table = [-1] * (n + 1)
        self.size = [1] * (n + 1)

    def merge(self, r1, r2):
        self.table[r1] = r2
        self.size[r2] += self.size[r1]
        self.size[r1] = 0

    def find_root(self, k):
        path = []
        curr = k
        while self.table[curr] != -1:
            path.append(curr)
            curr = self.table[curr]
        self.defrag(curr, path)
        return curr, path

    def defrag(self, r, p):
        for i in p:
            self.table[i] = r


def solve(string):
    n, m, *ab = map(int, string.split())
    ab = ab[::-1]
    ans = [n * (n - 1) // 2]
    table = uf(n)
    for _b, _a in zip(ab[::2], ab[1::2]):
        r_a, _ = table.find_root(_a)
        r_b, _ = table.find_root(_b)
        if r_a == r_b:
            ans.append(ans[-1])
            continue
        ans.append(ans[-1] - table.size[r_a] * table.size[r_b])
        table.merge(r_a, r_b)
    return "\n".join([str(a) for a in ans[:-1][::-1]])


if __name__ == '__main__':
    n, m = map(int, input().split())
    print(solve('{} {}\n'.format(n, m) + '\n'.join([input() for _ in range(m)])))