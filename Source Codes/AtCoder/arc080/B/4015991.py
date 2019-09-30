H,W = map(int,input().split())
N = int(input())
arr = [0] + list(map(int,input().split()))
c = [[-1]*W for _ in range(H)]
goto = [[0,1],[1,0],[0,-1],[-1,0]] #right,down,left,up


q = 1
h = 0
w = 0
cnt = 0
g = 0
count = 0

def judge(tmph,tmpw):
    ok = False
    if tmph >= 0 and tmph < H and tmpw >= 0 and tmpw < W:
        if c[tmph][tmpw] < 0:
            ok = True
    return ok
for _ in range(H*W):
    c[h][w] = q
    cnt += 1
    if cnt == arr[q]:
        q += 1
        cnt = 0
    tmph = h + goto[g][0]
    tmpw = w + goto[g][1]
    for i in range(4):
        if judge(tmph,tmpw):
            break
        g += 1
        g %= 4
        tmph = h + goto[g][0]
        tmpw = w + goto[g][1]
    h = tmph
    w = tmpw

for i in c:
    print(*i)