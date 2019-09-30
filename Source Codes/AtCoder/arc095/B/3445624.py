N=int(input())
A=list(map(int,input().split()))
A1=max(A)
A2=(-1)
for i in range(N):
    if A[i]==A1:
        pass
    elif abs(A1/2-A[i])<abs(A1/2-A2):
        A2=A[i]
print(A1,A2)