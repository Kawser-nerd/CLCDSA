from sys import stdin
N=int(stdin.readline().rstrip())
flag=0
for i in range(2,N):
  if N%i==0:
    flag=1
    break
if flag==0:
  print("YES")
else:
  print("NO")