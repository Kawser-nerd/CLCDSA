N = int(input())
B = list(map(int,input().split()))
order = sorted(enumerate(B),key=lambda x:x[1])

MAX = N+2
bit = [0] * (MAX+2)
def bit_add(i,w):
    x = i
    while x <= MAX:
        bit[x] += w
        x += (x & -x)

def bit_sum(i):
    if i == 0: return 0
    x = i
    ret = 0
    while x > 0:
        ret += bit[x]
        x -= (x & -x)
    return ret

def bit_range_sum(l,r):
    return bit_sum(r) - bit_sum(l)

for i in range(N):
    bit_add(i+1,1)

ans = 0
for i,_ in order:
    ans += min(bit_range_sum(0,i), bit_range_sum(i+1,N))
    bit_add(i+1, -1)
print(ans)