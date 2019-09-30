N,M=map(int,input().split())
S=set()
for i in range(M) :
  S.add(i+1)
for i in range(N) :
  A=list(map(int,input().split()))
  A=set(A[1:])
  S=S&A
print(len(S))