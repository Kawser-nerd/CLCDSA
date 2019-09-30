N,M,A,B=map(int,input().split())
*c,=[int(input()) for i in range(M)]
for i in range(M):
  if N<=A:
    N+=B
  if N<c[i]:
    print(i+1)
    break
  N-=c[i]
  if i==M-1:
    print("complete")