n = int(input())
a = list(map(int, input().split()))
b = [0]*(n+1)
l = [i for i in range(n+2)]
r = [i for i in range(n+2)]
ans = 0
for i in range(n):
    b[a[i]] = i

for i in range(n, 0, -1):
    m = b[i]
    x, y = l[m], r[m]
    ans += i*(m-x+1)*(y-m+1)
    l[y+1], r[x-1] = x, y
print(ans)