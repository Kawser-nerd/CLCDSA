N=40
K=int(input())
F=[0 for i in range(N+1)]
F[1]=1
F[0]=1
for i in range(2,N+1):
    F[i]=F[i-1]+F[i-2]
print(F[K-1],F[K])