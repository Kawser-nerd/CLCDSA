n, y = [int(i) for i in input().split(" ")]
a = 0
f = False

while y - 1000 * n - 9000 * a >= 0:
    r = (y - 1000 * n - 9000 * a)
    b = r // 4000
    if r % 4000 == 0 and n - a - b >= 0:
        print(a, b, n - a - b)
        f = True
        break
    a += 1

if not f:
    print(-1, -1, -1)