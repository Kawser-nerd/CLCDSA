L=int(input())
B=[int(input()) for i in range(L)]
A=[0 for i in range(L)]
for i in range(L-1):
    A[i+1]=A[i]^B[i]
if B[-1]==A[0]^A[-1]:
    for i in range(L):
        print(A[i])
else:
    print(-1)