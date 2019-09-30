import sys
from itertools import zip_longest as zip

T = int(sys.stdin.readline().strip())

def cost(v):
    v.sort()
    m = v[len(v) // 2]
    return sum(abs(i - m) for i in v)

def partition(s):
    i = 0
    while i < len(s):
        j = i + 1
        while j < len(s) and s[i] == s[j]:
            j += 1
        yield (s[i], j-i)
        i = j

for t in range(T):
    N = int(sys.stdin.readline().strip())
    ss = list(sys.stdin.readline().strip() for _ in range(N))
    res = 0
    for items in zip(*list(partition(s) for s in ss)):
        #print(items)
        if any(i is None for i in items):
            print("Case #%d: Fegla Won" % (t+1))
            break
        if any(a != items[0][0] for a, _ in items[1:]):
            print("Case #%d: Fegla Won" % (t+1))
            break
        res += cost(list(b for _, b in items))
    else:
        print("Case #%d: %d" % (t+1, res))

