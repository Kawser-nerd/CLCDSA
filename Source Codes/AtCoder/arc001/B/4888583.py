A,B = map(int,input().split())
X=0
if A<B:
  AA=A
  A=B
  B=AA
N=A-B
while N!=0:
  if N>=10:
    N=N-10
  elif N>=8 and N<=9:
    N=10-N
  elif N>=5 and N<=7:
    N=N-5
  elif N==4:
    N=1
  elif N>=1 and N<=3:
    N=N-1
  X=X+1
print(X)