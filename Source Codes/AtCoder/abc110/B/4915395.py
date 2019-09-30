import sys
n,m,X,Y=map(int,input().split())
x=list(map(int,input().split()))
y=list(map(int,input().split()))
for z in range(101):
  if X<z<=Y and all(x[i]<z for i in range(n)) and all(y[j]>=z for j in range(m)):
    print('No War')
    sys.exit()
for z in range(1,101):
  if X<z*(-1)<=Y and all(x[i]<z*(-1) for i in range(n)) and all(y[j]>=z*(-1) for j in range(m)):
    print('No War')
    sys.exit()
print('War')