n, k = map(int, input().split())
a = list(map(int, input().split()))

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

num = a[0]
for i in range(1, n):
    num = gcd(num, a[i])

if k > max(a):
    print("IMPOSSIBLE")
    exit()

if k % num == 0:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")