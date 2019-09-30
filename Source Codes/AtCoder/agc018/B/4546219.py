from collections import Counter
N, M = map(int, input().split())
a = [list(map(int, input().split()))[::-1] for _ in [0]*N]
ans = 1000
used = set()

try:
    while True:
        counter = Counter(h[-1] for h in a)
        mc, count = counter.most_common(1)[0]
        used.add(mc)
        if ans > count:
            ans = count
        for h in a:
            while h[-1] in used:
                h.pop()
except IndexError:
    print(ans)