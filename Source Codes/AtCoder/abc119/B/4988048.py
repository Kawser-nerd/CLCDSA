N = int(input())
rate = 380000.0
ans = 0.0

for i in range(N):
    x, u = input().split()
    x = float(x)
    ans += x * rate if u == 'BTC' else x
    
print('{:.11f}'.format(ans))