from scipy.sparse.csgraph import floyd_warshall
import numpy as np


def make_graph(m):
    matrix = np.zeros([m + 1, m + 1, m + 1])
    for k in range(1, m + 1):
        for s in range(k, m + 1):
            matrix[k, s, s % k] = 1
    return matrix


def is_disable(matrix, subset, aaa, bbb):
    if subset:
        sub_matrix = matrix[list(subset)].max(axis=0)
    else:
        sub_matrix = matrix[0]
    sp = floyd_warshall(sub_matrix)
    return any(sp[a, b] > 50 for a, b in zip(aaa, bbb))


def solve(aaa, bbb):
    for a, b in zip(aaa, bbb):
        if a < b:
            return -1
    m = max(aaa)
    matrix = make_graph(m)
    subset = set(range(1, m + 1))
    if is_disable(matrix, subset, aaa, bbb):
        return -1

    for k in range(m, 0, -1):
        subset.remove(k)
        if is_disable(matrix, subset, aaa, bbb):
            subset.add(k)
    return sum(1 << k for k in subset)


n = int(input())
aaa = list(map(int, input().split()))
bbb = list(map(int, input().split()))
print(solve(aaa, bbb))