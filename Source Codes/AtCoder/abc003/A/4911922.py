n = int(input())
ans = 0
if n == 0:
    print(n)
elif n != 0:
    for i in range(n + 1):
        ans += (i * 10000)
    ans = ans // n
    print(ans)