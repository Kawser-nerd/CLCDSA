C = input().replace('o','1').replace('x','0')
P = int(C,2)
N = len(C)

ans = N
mask = 2**(2*N-1) - 2**(N-1)
for b in range(1,2**N):
    ptn = cnt = 0
    for i in range(N):
        if b&(1<<i)==0: continue
        cnt += 1
        ptn |= (P<<i)
        ptn |= (P<<(i+N))
    if ptn&mask == mask:
        ans = min(ans, cnt)
print(ans)