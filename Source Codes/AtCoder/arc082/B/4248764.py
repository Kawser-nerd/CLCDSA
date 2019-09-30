N = int(input())
A = input().split()
A = [int(int(A[int(i)])==int(i)+1) for i in range(N)]
ans=0
for i in range(N-1):
  if A[i] and A[i+1]:
    A[i]=A[i+1]=0
    ans+=1
print(ans+sum(A))