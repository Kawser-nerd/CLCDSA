n = int(input())
h = [int(input()) for i in range(n)]

L = [1] * n
R = [1] * n

for i in range(1, n):
    if h[i-1] < h[i]:
        L[i] = L[i-1] + 1
for i in range(n-2, -1, -1):
    if h[i] > h[i+1]:
        R[i] = R[i+1] + 1
ans = 0
for i in range(n):
    ans = max(ans, L[i] + R[i])
print(ans - 1)