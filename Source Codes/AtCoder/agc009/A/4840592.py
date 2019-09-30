n = int(input())
a,b = [], []
for i in range(n):
    s,t = list(map(int, input().split()))
    a.append(s)
    b.append(t)

res = 0
for i in range(n-1, -1, -1):
    if not (a[i]+res)%b[i] == 0:
        res += b[i] - (a[i]+res)%b[i]
print(res)