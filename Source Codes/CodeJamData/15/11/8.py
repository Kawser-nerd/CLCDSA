tc = int(input().strip())

for t in range(tc):
    n = int(input().strip())
    v = list(int(x) for x in input().strip().split())

    a = sum(max(0, v[i] - v[i+1]) for i in range(n-1))
    b = max(max(0, v[i] - v[i+1]) for i in range(n-1))
    c = sum(min(b, v[i]) for i in range(n-1))

    print("Case #%d: %d %d" % (t+1, a, c))
