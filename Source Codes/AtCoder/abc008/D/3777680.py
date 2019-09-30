W,H = map(int,input().split())
N = int(input())
src = [tuple(map(int,input().split())) for i in range(N)]

mem = {}
def opt(x1,y1,x2,y2):
    if x1 > x2 or y1 > y2: return 0
    if (x1,y1,x2,y2) in mem:
        return mem[(x1,y1,x2,y2)]
    ret = 0
    for x,y in src:
        if not(x1 <= x <= x2) or not(y1 <= y <= y2): continue
        tmp = (x2-x1+1) + (y2-y1+1) - 1
        tmp += opt(x1,y1,x-1,y-1)
        tmp += opt(x1,y+1,x-1,y2)
        tmp += opt(x+1,y1,x2,y-1)
        tmp += opt(x+1,y+1,x2,y2)
        ret = max(ret, tmp)
    mem[(x1,y1,x2,y2)] = ret
    return ret

print(opt(1,1,W,H))