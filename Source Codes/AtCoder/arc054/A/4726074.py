L,X,Y,S,D = map(int,input().split())
t = 0
if D == S:
    t = 0
elif D > S:
    if X>=Y:
        t = (D-S)/(X+Y)
    else:
        s = (D-S)/(X+Y)
        r = (L-D+S)/(Y-X)
        t = min(s,r)
else:
    if X>=Y:
        t = (L-S+D)/(X+Y)
    else:
        s = (L-S+D)/(X+Y)
        r = (S-D)/(Y-X)
        t = min(s,r)
print(t)