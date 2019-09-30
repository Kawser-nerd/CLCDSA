import sys
n=int(input())
c=[int(i) for i in sys.stdin]
x=[0]*(200001)
c.append(0)
x[c[0]]+= 1
num=1
p=10**9 +7
for i in range(1,n):
  if c[i]-c[i-1]:
    x[c[i]]+= num
    x[c[i]]= x[c[i]]%p
  if c[i]-c[i+1]:
    num=x[c[i]]%p
  else:
    num=0
print(num)