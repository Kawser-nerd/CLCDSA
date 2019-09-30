import math
n = int(input())
ans = 1e10
for i in range(1, int(math.sqrt(n)) + 1) :
  if(n % i == 0) :
    ans = min(ans, int(math.log10(n/i)))
print(ans+1)