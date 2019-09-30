H,W = map(int,input().split())
A = [list(input()) for i in range(H)]
a = 0
for h in range(H):
    for w in range(W):
        if A[h][w] == '#':
            a += 1
h = 0
w = 0
d = 0
fh = False
fw = False
while True:
    if h == H-1 and w == W-1:
        break
    
    if h == H-1:
        fh = True
    if w == W-1:
        fw = True
        
    if h < H-1:
        if A[h+1][w] == '#':
            h += 1
            d += 1
        elif fw:
            break
    if w < W-1:
        if A[h][w+1] == '#':
            w += 1
            d += 1
        elif fh:
            break
    
if a == d+1:
    print('Possible')
else:
    print('Impossible')