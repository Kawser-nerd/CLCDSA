#!/usr/bin/env python
import sys

def solve_one_short(n, horses, d, queries):
    assert(n == len(horses))
    assert(n == len(d))
    time = [1e100] * n
    time[n - 1] = 0.0
    for i in reversed(range(n - 1)):
        e, s = horses[i]
        dist = 0
        for j in range(i + 1, n):
            dist += d[j - 1][j]
            if dist > e:
                break
            time[i] = min(time[i], time[j] + dist / s)
    return str(time[0])
def floyd(dist):
    n = len(dist)
    shortest = []
    for i in range(n):
        shortest.append([1e1000] * n)
        shortest[i][i] = 0
        for j in range(n):
            if dist[i][j] < 0.0:
                shortest[i][j] = 1e1000
            else:
                shortest[i][j] = dist[i][j]
    for k in range(n):
        for i in range(n):
            for j in range(n):
                shortest[i][j] = min(shortest[i][j], shortest[i][k] + shortest[k][j])
    return shortest

def solve_one(n, horses, d, queries):
    assert(n == len(horses))
    assert(n == len(d))
    shortest = floyd(d)

    for i in range(n):
        e, s = horses[i]
        for j in range(n):
            if shortest[i][j] > e:
                shortest[i][j] = -1.0
            else:
                shortest[i][j] /= s
    shortest = floyd(shortest)
    res = []
    for u, v in queries:
        res.append(shortest[u][v])

    return " ".join(map(str, res))

def solve(data):
    def lines():
        for line in data.split("\n"):
            yield line
    lines_iter = lines()
    def next_line():
        return lines_iter.__next__()
    res = []
    T = int(next_line())
    cur_line = 1
    for ncase in range(1, 1 + T):
        # read test case
        n, q = map(int, next_line().split())
        horses = []
        for i in range(n):
            e, s = map(int, next_line().split())
            horses.append((e, s))
        d = []
        for i in range(n):
            d.append(list(map(int, next_line().split())))
        queries = []
        for i in range(q):
            u, v = map(int, next_line().split())
            queries.append((u - 1, v - 1))
        ans = solve_one(n, horses, d, queries)
        res.append("Case #%d: %s" % (ncase, ans))
    return "\n".join(res)

def solve_files(infile, outfile):
    data = infile.read()
    result = solve(data)
    outfile.write(result)

def main():
    infile = sys.stdin
    outfile = sys.stdout
    if len(sys.argv) > 1:
        infile = open(sys.argv[1], "rt")
    if len(sys.argv) > 2:
        outfile = open(sys.argv[2], "wt")
    solve_files(infile, outfile)
    outfile.close()

if __name__ == "__main__":
    main()

    
