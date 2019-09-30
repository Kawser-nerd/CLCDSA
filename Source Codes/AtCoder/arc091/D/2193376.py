N = int(input())
grundy = 0
for i in range(N):
    a, k = map(int, input().split())
    while a % k:
        p, q = divmod(a, k)
        a -= (p + 1)*((p+q)//(p+1))
    grundy ^= a // k
print('Takahashi' if grundy else 'Aoki')