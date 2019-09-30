N=int(input())
A=[]
for i in range(N):
    A.append(int(input()))

B=sorted(A)

C=[]
D=[]

for i in range(N):
    if i%2==0:
        C.append(A[i])
        D.append(B[i])
        
print((N+1)//2-len(set(C) & set(D)))