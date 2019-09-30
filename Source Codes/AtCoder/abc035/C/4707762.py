n, q = map(int, input().split())

L = [0] * n
R = [0] * (n + 1)

for _ in range(q):
    l, r = map(int, input().split())
    L[l-1] += 1
    R[r] += 1

ans = [0] * n
temp = 0
for i in range(n):
    temp += L[i] - R[i]
    ans[i] = str(temp % 2)

print(''.join(ans))