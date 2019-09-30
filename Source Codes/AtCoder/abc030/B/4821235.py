n, m = map(int, input().split())


b = m * 6
a = (n % 12 + m / 60) * 30

ans = abs(a-b)

if ans <= 180:
    print(ans)
else:
    print(360-ans)