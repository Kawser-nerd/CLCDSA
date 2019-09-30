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
        return curr, path

    def defrag(self, r, p):
        for i in p:
            self.table[i] = r

    def defrag_all(self):
        for i in range(len(self.table)):
            if self.table[i] == -1:
                continue
            self.defrag(*self.find_root(i))

    def in_same_group(self, k1, k2):
        r1, p1 = self.find_root(k1)
        r2, p2 = self.find_root(k2)
        if r1 == r2:
            self.defrag(r1, p1 + p2)
        else:
            self.defrag(r1, p1)
            self.defrag(r2, p2)
        return r1 == r2


def cul_comb(n):
    return n * (n - 1) // 2


def solve(string):
    n, m, *ab = map(int, string.split())
    ab = ab[::-1]
    ans = [cul_comb(n)]
    table = uf(n)
    for _b, _a in zip(ab[:2 * m - 2:2], ab[1:2 * m - 2:2]):
        if table.in_same_group(_b, _a):
            ans.append(ans[-1])
        else:
            r_a, p_a = table.find_root(_a)
            r_b, p_b = table.find_root(_b)
            ans.append(ans[-1] - table.size[r_a] * table.size[r_b])
            table.merge(r_a, r_b)
            table.defrag(r_b, p_a)
            table.defrag(r_b, p_b)
    return "\n".join([str(a) for a in ans[::-1]])


if __name__ == '__main__':
    n, m = map(int, input().split())
    print(solve('{} {}\n'.format(n, m) + '\n'.join([input() for _ in range(m)])))