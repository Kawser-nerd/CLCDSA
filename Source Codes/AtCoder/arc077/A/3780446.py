N=int(input())
A=list(map(int,input().split()))
B=[0 for i in range(N)]
if N%2==0:
    for i in range(N):
        B[N//2+(i//2+i%2)*((-1)**i)]=A[i]
else:
    for i in range(N):
        B[N//2+(i//2+i%2)*((-1)**(i+1))]=A[i]
for j in range(N):
    print(B[j], end=' ')
print()