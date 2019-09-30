N=int(input())
A=list(map(int, input().split()))
#A=list(set(A))

for i, a in enumerate(A):
  while a%2==0:
    a=a//2
  A[i]=a
  
print(len(set(A)))