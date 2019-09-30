H,W = map(int,input().split())
S = [input() for i in range(H)]

A = [['.']*W for i in range(H)]
dxy = [(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1),(-1,0),(-1,1)]

for y in range(H):
    for x in range(W):
        if S[y][x] == '.': continue
        for dx,dy in dxy:
            nx,ny = x+dx,y+dy
            if not 0 <= nx < W: continue
            if not 0 <= ny < H: continue
            if S[ny][nx] == '.': break
        else:
            A[y][x] = '#'

B = [['.']*W for i in range(H)]
for y in range(H):
    for x in range(W):
        if A[y][x] == '.': continue
        B[y][x] = '#'
        for dx,dy in dxy:
            nx,ny = x+dx,y+dy
            if not 0 <= nx < W: continue
            if not 0 <= ny < H: continue
            B[ny][nx] = '#'

for sr,br in zip(S,B):
    for s,b in zip(sr,br):
        if s != b:
            print('impossible')
            exit()
print('possible')
for row in A:
    print(*row, sep='')