import jam
import sys
sys.setrecursionlimit(10000)

def solve(case):
    N = case.readInt()
    lists = []
    for i in range(2 * N - 1):
        lists.append([case.readInt() for i2 in range(N)])
    count = {}
    for q in lists:
        for h in q:
            if h in count:
                count[h] += 1
            else:
                count[h] = 1
    result = []
    for h in count:
        if count[h] % 2 == 1:
            result.append(h)
    result.sort()
    return " ".join(str(h) for h in result)

jam.run("B-large.in", solve)
