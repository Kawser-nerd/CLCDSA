H,W,N = map(int,input().split())
src = [tuple(map(int,input().split())) for i in range(N)]
objs = [[] for i in range(H)]
for y,x in src:
    objs[y-1].append(x-1)

maxx = 0
for i,row in enumerate(objs[1:]):
    if row and min(row) <= maxx:
        print(i+1)
        exit()
    if maxx == W-1: continue
    if maxx+1 not in row:
        maxx += 1
print(H)