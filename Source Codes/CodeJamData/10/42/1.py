import sys
rl = lambda: sys.stdin.readline().strip()

M = 987654321

def go(y, x, missed):
    if y == p:
        if miss[x] < missed:
            return M
        return 0
    key = (y, x, missed)
    if key in cache: return cache[key]
    ret = go(y+1, x*2, missed+1) + go(y+1, x*2+1, missed+1)
    ret = min(ret, price[y][x] + go(y+1, x*2, missed) + go(y+1, x*2+1, missed))
    #print key, "=>", ret
    cache[key] = ret
    return ret


t = int(rl())
for cc in range(t):
    p = int(rl())
    n = 2**p
    miss = map(int, rl().split())
    price = []
    for i in range(p-1,-1,-1):
        m = 2**i
        price.append(map(int, rl().split()))
    price = list(reversed(price))
    cache = {}
    print "Case #%d: %d" % (cc+1, go(0, 0, 0))
