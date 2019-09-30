ans = 2**32+1
n = int(input())

for i in range(1, 1001):
    for j in range(1, 1001):
        if i*j<=n:
            ans = min(ans, abs(i-j)+n-(i*j))
print(ans)