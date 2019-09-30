T = input()

for t in range(T):
    n = input()
    v = map(int, raw_input().split())
    x = 0
    y = 0
    z = 0
    for i in range(n-1):
        if v[i] > v[i+1]:
            x += v[i]-v[i+1]
            y = max(y, v[i] - v[i+1])
    for i in range(n-1):
        z += min(v[i], y)
    print "Case #%d: %d %d"%(t+1, x, z)
