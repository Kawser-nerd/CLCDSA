n = int(input())
a = []
b = []
for i in range(n):
    A, B = map(int, input().split())
    a.append(A)
    b.append(B)
a.reverse()
b.reverse()
ans = 0
for i in range(n):
    if (a[i] + ans) % b[i]:
        ans += b[i] - (a[i] + ans) % b[i]
print(ans)