N, T = map(int, input().split())
t = [int(_) for _ in input().split()]
res = 0

for i in range(N-1):
    res += max(0, T - (t[i+1] - t[i]))

print(N*T-res)