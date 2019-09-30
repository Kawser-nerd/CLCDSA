import bisect
N=int(input())

O=[]
E=[]
A=[]
for i in range(N):
    a=int(input())
    A.append(a)
    if i%2==0:
        O.append(a)
    else:
        E.append(a)
        
A.sort()
Odd=0
Eve=0
for i in range(len(O)):
    if bisect.bisect_left(A,O[i])%2==0:
        Odd+=1
    else:
        Eve+=1
print(Eve)