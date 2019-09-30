n, x = map(int, input().split())
x = list(bin(x)[2::][::-1])
price = list(map(int, input().split()))
ans = 0
for i, flag in enumerate(x) :
    if int(flag) :
        ans += price[i]
print(ans)