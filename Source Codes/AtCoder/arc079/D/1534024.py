from collections import defaultdict
import heapq as hq


def helper(n):
    q = child_L[n]
    del child_L[n]

    hq.heapify(q)
    i = 0
    while q:
        t = hq.heappop(q)
        if i < t:
            break
        else:
            i += (i == t)

    j = i + 1
    while q:
        t = hq.heappop(q)
        if j < t:
            break
        else:
            j += (j == t)

    return (i, j)


if __name__ == '__main__':

    N = int(input())
    P = list(map(lambda x: int(x) - 1, input().split()))
    # D:?????????
    D = [0] * N
    for p in P:
        D[p] += 1
    # print(D)
    child_L = defaultdict(list)
    # S:????????????
    S = [p for p in range(N) if D[p] == 0]

    L = [None] * N

    while S:
        # print(child_L)
        n = S.pop()

        q = child_L[n]
        # print(q)
        del child_L[n]

        # list?q??????????
        hq.heapify(q)
        i = 0
        while q:
            t = hq.heappop(q)
            if i < t:
                break
            else:
                i += (i == t)

        L[n] = i
        # print(L)
        m = P[n]
        # print("m:" + str(m))
        child_L[m].append(i)
        D[m] -= 1
        if D[m] == 0:
            S.append(m)

    # print(D)
    # cycle check
    try:
        start = D.index(1)
    except ValueError:
        print('POSSIBLE')
        exit()

    s1, s2 = helper(start)
    G = []
    n = P[start]
    while n != start:
        G.append(helper(n))
        n = P[n]

    # del N, P, D, child_L, S, L

    # ?????????????????
    # 1
    n = s1
    for g in G:
        if g[0] == n:
            n = g[1]
        else:
            n = g[0]
    if n != s1:
        print('POSSIBLE')
        exit()

    # 2
    n = s2
    for g in G:
        if g[0] == n:
            n = g[1]
        else:
            n = g[0]
    if n == s1:
        print('POSSIBLE')
        exit()

    print('IMPOSSIBLE')