d = {}

N = int(input())
for i in range(N):
    s = input()
    d[s] = d.get(s, 0) + 1

M = int(input())
for i in range(M):
    t = input()
    d[t] = d.get(t, 0) - 1

print(max(max(d.values()), 0))