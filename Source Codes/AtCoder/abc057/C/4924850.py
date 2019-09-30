import math
N = int(input())
n = int(math.sqrt(N))
ans = float('inf')
for i in range(1,n+1):
  if(N%i == 0):
    a,b = i,N//i
    a,b = str(a),str(b)
    tmp = max(len(a),len(b))
    ans = min(ans,tmp)
print(ans)