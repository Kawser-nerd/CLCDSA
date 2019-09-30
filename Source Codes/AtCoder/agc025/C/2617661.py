N = int(input())
L,R = [],[]
for i in range(N):
    l,r = map(int,input().split())
    L.append(l)
    R.append(r)

# ?????
L.append(0)
R.append(0)

# ??????????????????
L.sort(reverse=True)
R.sort()

Ans = 0
for i in range(N+1):
    if L[i] > R[i]:
        Ans += (L[i] - R[i])*2

print(Ans)