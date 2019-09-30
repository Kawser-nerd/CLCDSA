N=int(input())
D,X=map(int,input().split())
M=0
for i in range(N) :
  A=int(input())
  for i in range(100):
    if (A*i+1) <= D :
      M+=1
    else :
      break
print(M+X)