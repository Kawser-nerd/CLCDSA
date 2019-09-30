def mhd(sx, sy, tx, ty):
    return(abs(sx-tx)+abs(sy-ty))
def inpl(): return [int(i) for i in input().split()]

N = int(input())
Sx, Sy, St = 0, 0, 0
ans = 'Yes'
for _ in range(N):
    Tt, Tx, Ty = inpl()
    if mhd(Sx, Sy, Tx, Ty) > Tt-St or (mhd(Sx, Sy, Tx, Ty) - Tt + St) % 2:
        ans = 'No'
print(ans)