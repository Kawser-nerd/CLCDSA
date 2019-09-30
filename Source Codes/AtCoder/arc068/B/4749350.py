N = int(input())
A = list(map(int, input().split()))
d = [0] * 100001
ans = 0
for i in A:
    if d[i] >0:
        ans += 1
    d[i] += 1
print(N - ((ans + 1) // 2) * 2)