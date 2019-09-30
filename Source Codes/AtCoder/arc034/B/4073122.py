def f(x):
    res=0
    for a in str(x):
        res+=int(a)
    return res
N=int(input())
L=[]
for i in range(max(0,N-200),N+1):
    if i+f(i)==N:
        L.append(i)
print(len(L))
for i in L:
    print(i)