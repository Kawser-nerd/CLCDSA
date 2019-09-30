import math
X,Y = map(int,input().split())
#a_n = X*2^(n-1)
count = 1
while(1):
  if(Y < 2*X):
    break
  X = X*2
  count += 1

print(count)