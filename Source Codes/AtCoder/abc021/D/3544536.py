p = 1000000007
n = int(input())
k = int(input())
a = [0]*(k+1)
a[1] = 1
for i in range(2,k+1):
  a[i] = a[p%i]*(p-p//i)%p
s = 1
for j in range(k):
  s = s*(n+k-1-j)%p
  s = s*a[j+1]%p
print(s)