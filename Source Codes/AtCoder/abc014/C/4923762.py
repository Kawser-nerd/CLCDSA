N = int(input())
t = [0] * (1000002)
for _ in range(N):
    a, b = map(int, input().split())
    t[a] += 1
    t[b+1] -= 1
for i in range(1000001):
    t[i+1] += t[i]
print(max(t))