N = int(input())
A = [int(i) for i in input().split()]
c4=0
c2=0
for i in range(N):
  if A[i]%4==0:
    c4+=1
  elif A[i]%2==0:
    c2+=1
if c4:
  a = c4*2+1
else:
  a = 0
if c2>1:
  b = c2
  if a:
    a -= 1
else:
  b = 0
if a+b>=N:
  print("Yes")
else:
  print("No")