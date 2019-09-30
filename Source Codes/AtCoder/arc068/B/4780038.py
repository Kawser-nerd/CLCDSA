N=int(input())
A=[int(i) for i in input().split()]

st=set(A)
res = len(st)
if (N-res)%2==0:
    print(res)
else:
    print(res-1)