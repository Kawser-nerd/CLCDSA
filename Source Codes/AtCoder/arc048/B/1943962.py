N = int(input())
MAXR = 10**5

src = []
mem = [[0,0,0] for i in range(MAXR)]

for i in range(N):
    r,h = map(lambda x:int(x)-1,input().split())
    src.append((r,h))
    mem[r][h] += 1

cums = [0]
for i in range(MAXR):
    cums.append(cums[-1] + sum(mem[i]))

res = [None for i in range(MAXR)]
for r,h in src:
    if res[r] is None:
        win = cums[r]
        lose = N - win - sum(mem[r])
        g,c,p = mem[r]
        res[r] = ((win+c,lose+p,g-1), (win+p,lose+g,c-1), (win+g,lose+c,p-1))
    print(' '.join(map(str,res[r][h])))