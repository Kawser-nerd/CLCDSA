N, M = map(int, input().split())
A = [ int(x) for x in input().split() ]

d = {0:1}
ans, s = 0, 0
 
for a in A:
    s += a
    s %= M
    ans += d.get(s, 0)
    d[s] = d.get(s, 0) + 1

print(ans)