N=int(input())
T,A=map(int,input().split())
H=[int(i) for i in input().split()]
d=10**4
n=0
for j in range(N):
  dj=abs(A-(T-H[j]*0.006))
  if dj<d:
    d=dj
    n=j
print(n+1)