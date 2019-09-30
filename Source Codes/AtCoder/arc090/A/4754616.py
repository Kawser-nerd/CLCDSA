N=int(input())
x=list(map(int,input().split()))
y=list(map(int,input().split()))
a=[0]*(N)
for i in range(N):
  for k in range(i+1):
    a[i]+=x[k]
  for j in range(N-i):
    a[i]+=y[j+i]

print(max(a))