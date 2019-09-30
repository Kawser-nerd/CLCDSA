#!/usr/bin/env python3
import sys, heapq


def solve(N: int, K: int, t: "List[int]", d: "List[int]"):
    group = {}
    for i in range(N):
        k = t[i]
        v = d[i]
        if k in group:
            group[k].append(v)
        else:
            group[k] = [v]
    groups = list(group.values())
    for g in groups:
        g.sort(reverse=True)
    groups.sort(reverse=True, key=lambda x: x[0])
    h = []
    ret = 0
    base = 0
    #print(groups)
    for i in range(min(len(groups), K)):
        g = groups[i]
        bonus = (i + 1) ** 2
        for j, v in enumerate(g):
            if j == 0:
                if len(h) > K - (i + 1):
                    remove = heapq.heappop(h)
                else:
                    remove = 0
                base = base - remove + v
            elif len(h) < K - (i + 1):
                heapq.heappush(h, v)
                base += v
            elif len(h) > 0 and h[0] < v:
                base += v - h[0]
                heapq.heapreplace(h, v)
            ret = max(ret, base + bonus)
            #print(h)
            #print("bonus : %d, base : %d, ret : %d" % (bonus, base, ret))
            #print(' --- ')
    print(ret)
    return


def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    K = int(next(tokens))  # type: int
    t = [int()] * (N)  # type: "List[int]" 
    d = [int()] * (N)  # type: "List[int]" 
    for i in range(N):
        t[i] = int(next(tokens))
        d[i] = int(next(tokens))
    solve(N, K, t, d)

if __name__ == '__main__':
    main()