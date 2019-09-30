def getdigit(N):
  cnt = 0
  while(N>0):
    cnt += 1
    N //= 10
  return cnt

N = int(input())
for i in reversed(range(1,int(pow(N, 1/2))+1)):
  if(N % i == 0):
    print(max(getdigit(i), getdigit(N/i)))
    exit()