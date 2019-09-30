n=int(input())
a=[0]*9
b=0
for i in [0]*n:
  x=input()
  for j in range(9):
    if x[j]=="o":
      b+=(a[j]==0)
      a[j]=1
    else:
      b+=(x[j]=="x")
      a[j]=0
print(b)