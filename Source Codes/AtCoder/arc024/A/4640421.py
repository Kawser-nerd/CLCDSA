l,r = map(int,input().split())
L = list(map(int,input().split()))
R = list(map(int,input().split()))
ans = 0
if min(r,l) == r:
    for i in range(r):
        if R[i] in L:
            del L[L.index(R[i])]
            ans += 1
else:
    for i in range(l):
        if L[i] in R:
            del R[R.index(L[i])]
            ans += 1
print(ans)