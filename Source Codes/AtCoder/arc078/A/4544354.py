a = int(input())
x = list(map(int, input().split()))
s = sum(x)
inf = float('INF')
m = inf
S=0
for i in range(a-1):
    s-=x[i]
    S+=x[i]
    m = min(m,abs(s-S))

print(m)