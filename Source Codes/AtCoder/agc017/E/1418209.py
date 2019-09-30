import sys
from collections import Counter

# sys.stdin = open('e1.in')


def read_int_list():
    return list(map(int, input().split()))


def read_int():
    return int(input())


def read_str_list():
    return input().split()


def read_str():
    return input()


total_in = 0
total_out = 0


def solve():
    n, h = read_int_list()
    a, b, c, d = zip(*[read_int_list() for _ in range(n)])
    n_nodes = 2 * h + 1
    n_edges = n
    adj = [[] for _ in range(n_nodes)]
    r_adj = [[] for _ in range(n_nodes)]
    for i in range(n_edges):
        if c[i] == 0:
            l = a[i]
        else:
            l = -c[i]
        if d[i] == 0:
            r = -b[i]
        else:
            r = d[i]
        adj[l + h].append(r + h)
        r_adj[r + h].append(l + h)
    in_degree = Counter()
    out_degree = Counter()
    for i in range(n_nodes):
        for j in adj[i]:
            out_degree[i] += 1
            in_degree[j] += 1

    for i in range(n_nodes):
        if i < h:
            if not out_degree[i] <= in_degree[i]:
                return 'NO'
        if h < i:
            if not in_degree[i] <= out_degree[i]:
                return 'NO'

    state = [0] * n_nodes

    def dfs(root):
        res = False
        state[root] = 1
        for i in adj[root]:
            if state[i] == 0:
                res |= dfs(i)
        for i in r_adj[root]:
            if state[i] == 0:
                res |= dfs(i)
        state[root] = 2
        if (in_degree[root], out_degree[root]) == (0,0):
            return True
        res |= in_degree[root] != out_degree[root]
        return res

    for i in range(n_nodes):
        if state[i] == 0:
            if not dfs(i):
                return 'NO'

    return 'YES'


def main():
    res = solve()
    print(res)


if __name__ == '__main__':
    main()