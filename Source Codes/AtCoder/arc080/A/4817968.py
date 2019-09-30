N = int(input())
A = [int(a) for a in input().split()]

t4=0
t2=0
t=0
for a in A:
  if a%4==0:
    t4+=1
  elif a%2==0:
    t2+=1
  else:
    t+=1
if t4>=t or (t2==0 and t4+1==t):
  print("Yes")
else:
  print("No")