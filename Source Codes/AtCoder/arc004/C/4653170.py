x, y = map(int, input().split('/'))

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


x, y = x // gcd(x, y), y // gcd(x, y)
if x < y:
    print('Impossible')
    exit()

n1 = 2 * x // y
n2 = 2 * x // y + 1
flag = False
if n1 % y == 0:
    m = n1 * (n1 + 1) // 2 - n1 * x // y
    if 1 <= m <= n1:
        flag = True
        print(n1, m)

if n2 % y == 0:
    m = n2 * (n2 + 1) // 2 - n2 * x // y
    if 1 <= m <= n2:
        flag = True
        print(n2, m)

if not flag:
    print('Impossible')