N,T=map(int,input().split())
A=list(map(int,input().split()))
i=0
j=1
a=0
b=0
while i<=N-1:
    if j==N:
        i=N
    elif A[i]>A[j]:
        i=j
        j+=1
    else:
        if A[j]-A[i]>a:
            a=A[j]-A[i]
            b=1
            j+=1
        elif A[j]-A[i]==a:
            b+=1
            j+=1
        elif A[j]-A[i]<a:
            j+=1
print(b)