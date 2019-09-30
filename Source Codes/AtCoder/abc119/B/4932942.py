#ABC119 B
N = int(input())
ans = 0
for i in range(N):
    x, v = input().split()
    x = float(x)
    if v == "BTC":
        x *= 380000
    ans += x 
print(ans)