def lower_bound(l,x):
    imin = -1
    imax = len(l)
    while imax-imin>1:
        imid = (imax+imin)//2
        if l[imid] >= x:
            imax = imid
        else:
            imin = imid
    if imax == len(l):
        return -1
    return l[imax]

NA,NB = map(int,input().split())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
B.sort()
AB = 0
for i in A:
    if lower_bound(B,i)==i:
        AB += 1
print(AB/(NA+NB-AB))