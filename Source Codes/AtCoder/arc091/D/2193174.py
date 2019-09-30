def extgcd(a, b):
    if b:
        d, y, x = extgcd(b, a%b)
        y -= (a/b)*x
        return d, x, y
    else:
        return a, 1, 0
N = int(input())
grundy = 0
for i in range(N):
    a, k = map(int, input().split())
    while a % k:
        p, q = divmod(a, k)
        a -= (p + 1)*((q+p)//(p+1))

    grundy ^= a // k
print('Takahashi' if grundy else 'Aoki')