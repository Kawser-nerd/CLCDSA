N,K = map(int,input().split())
src = [int(input()) for i in range(N)]

cums = [(0,1)]
for i,a in enumerate(src):
    cums.append((cums[-1][0] + a - K, i+2))

bit = [0] * (N+2)
def bit_add(a,w):
    x = a
    while x <= N:
        bit[x] += w
        x += (x & -x)

def bit_sum(a):
    x = a
    ret = 0
    while x > 0:
        ret += bit[x]
        x -= (x & -x)
    return ret

ans = 0
for i,a in sorted(cums):
    ans += bit_sum(a-1)
    bit_add(a, 1)
print(ans)