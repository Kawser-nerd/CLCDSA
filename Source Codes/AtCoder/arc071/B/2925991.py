n, m = [int(i) for i in input().split()]
X = [0] + [int(i) for i in input().split()]
Y = [0] + [int(i) for i in input().split()]

p = 10 ** 9 + 7

xsum = 0
ysum = 0

for i in range(1, n+1):
  xsum += (2*i-n-1) * X[i] 
  
for i in range(1, m+1):
  ysum += (2*i-m-1) * Y[i] 

print(xsum * ysum % p)