X, Y = map(int, input().split())
K = int(input())

if K <= Y:
    ans = X + K
else:
    ans = X - (K - Y) + Y
    
print(ans)