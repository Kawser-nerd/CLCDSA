n, d = map(int, input().split())
x, y = map(int, input().split())

if x % d != 0 or y % d != 0:
    print(0)
    exit()

x_least = x // d
y_least = y // d

if x_least + y_least > n:
    print(0)
    exit()

if (n - (x_least + y_least)) % 2 != 0:
    print(0)
    exit()

fac = [1, 1]
f = 1
for i in range(2, n+1):
    f *= i
    fac.append(f)

rest = (n - (x_least + y_least)) // 2
ans = 0
for i in range(rest + 1):
    up = y_least + i
    down = i
    right = x_least + (rest - i)
    left = rest - i
    ans += fac[n] // (fac[up] * fac[down] * fac[right] * fac[left])

print(ans / 4**n)