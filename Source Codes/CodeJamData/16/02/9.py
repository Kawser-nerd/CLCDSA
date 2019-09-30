tnum = int(raw_input())

def f(s):
    return ''.join([s[i] for i in range(len(s)) if i==0 or s[i]!=s[i-1]])

ngb = dict()

def g(s):
    if s in ngb:
        return
    ngb[s] = []
    for i in range(0, len(s)+1):
        t = ''.join(['-' if x=='+' else '+' for x in reversed(s[:i])])+s[i:]
        ngb[s].append(f(t))
        g(f(t))

for tcou in range(tnum):
    s = f(raw_input().strip())
    ngb.clear()
    g(s)
    dist = {x: None for x in ngb}
    dist['+'] = 0
    while True:
        change = False
        for x in ngb:
            for y in ngb[x]:
                if dist[y] is not None and (dist[x] is None or dist[x]>dist[y]+1):
                    dist[x] = dist[y]+1
                    change = True
        if not change:
            break
    print "Case #{}: {}".format(tcou+1, dist[s])
