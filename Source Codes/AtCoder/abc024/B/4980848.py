n, t = map(int, input().split())
o = [int(input()) for _ in range(n)]
for i in range(n-1):
    o[i] = max(0, o[i] - o[i+1] + t)
print(n * t - sum(o) + o.pop(-1))