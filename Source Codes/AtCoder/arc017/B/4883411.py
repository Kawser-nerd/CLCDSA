N,K = map(int,input().split())
pre_i = 0
c = 1
g = 0
for _ in range(N):
    i = int(input())
    if pre_i == 0:
        pre_i = i
        c = 1
    elif pre_i < i:c += 1
    else:
        g += max(0,c-K+1)
        c = 1
    pre_i = i
else:g += max(0,c-K+1)
print(g)