N = int(input())

gifts = []
for _ in range(N):
    x, u = map(str, input().split())
    gifts.append([float(x), u])
    
ans = 0.0
for g in gifts:
    x = g[0]
    u = g[1]
    
    if u == 'JPY':
        ans += x
    
    if u == 'BTC':
        ans += x * 380000.0

print(ans)