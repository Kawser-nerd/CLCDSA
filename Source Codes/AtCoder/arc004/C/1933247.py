def gcd(x, y):
    return gcd(y, x % y) if y > 0 else x

tmp = list(map(int, input().split('/')))
x = tmp[0]
y = tmp[1]
po = gcd(x, y)
x = x // po
y = y // po
yo = 0
for i in range(1, 5):
    n = int(int(2 * x / y) - 1 + i)
    
    if n % y > 0:
        continue

    si = n * (n + 1) // 2
    na = x * n // y
    m = si - na
    if 1 <= m and m <= n:
        print(n, m)
        yo = 1

if yo == 0:
    print("Impossible")