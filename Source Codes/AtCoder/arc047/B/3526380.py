N = int(input())
src = [tuple(map(int,input().split())) for i in range(N)]

INF = float('inf')
mina = minb = INF
maxa = maxb = -INF
for x,y in src:
    a,b = x+y, x-y
    mina = min(a, mina)
    minb = min(b, minb)
    maxa = max(a, maxa)
    maxb = max(b, maxb)

d = max(maxa-mina, maxb-minb)

a_cands = [maxa - d//2, mina + d//2]
b_cands = [maxb - d//2, minb + d//2]

for a in a_cands:
    for b in b_cands:
        x,y = (a+b)//2, (a-b)//2
        x0,y0 = src[0]
        d0 = abs(x-x0) + abs(y-y0)
        for xi,yi in src[1:]:
            di = abs(x-xi) + abs(y-yi)
            if d0 != di:
                break
        else:
            print(x,y)
            exit()