N = int(input())
def sumof(N):
  sum = 0
  while(N>0):
    sum += N % 10
    N //= 10
  return sum

minsum = 9*10
for i in range(1,N//2+1):
  minsum = min(minsum,sumof(i) + sumof(N-i))
print(minsum)