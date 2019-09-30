import bisect
bisect.bisect_left
N= int(input())
E = [None]*N
for i in range(N):
    u,v = list(map(int,input().split()))
    E[i]=(u,-v)
E.sort()
h = -E[0][1]
L = [h]
dp = [1]*N
for i in range(N):
     h = -E[i][1]
     if L[-1]<h:
        L.append(h)
     else :
        L[bisect.bisect_left(L,h)] = h
        
print(len(L))