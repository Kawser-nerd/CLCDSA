def inpl(): return [int(i) for i in input().split()]

A, B = inpl()

def nextin(nwin):
    nx, ny = nwin
    if nx != 98:
        return(nx+2, ny)
    else:
        return(0,ny+2)

Wh = [['#' for _ in range(100)] for _ in range(50)]
nowin = [0,0]
for _ in range(A-1):
    ix, iy = nowin
    Wh[iy][ix] = '.'
    nowin = nextin(nowin)

Bl = [['.' for _ in range(100)] for _ in range(50)]
nowin = [0,1]
for _ in range(B-1):
    ix, iy = nowin
    Bl[iy][ix] = '#'
    nowin = nextin(nowin)
print('100','100')
for i in range(50):
    print(''.join(Wh[i]))

for j in range(50):
    print(''.join(Bl[j]))