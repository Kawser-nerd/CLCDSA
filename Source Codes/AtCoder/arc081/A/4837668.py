N = int(input())
A = list(map(int,input().split()))
dic = {} #key(?????????max:10**5/2 = 5*10**4) -> sort???TLE
max1,max2 = 0,0
count = 0

for i in range(N):
  if(A[i] in dic):
    dic[A[i]] += 1
    if(dic[A[i]]%2 == 0):
      count += 1
      if(max1 < A[i]):
        max2 = max1
        max1 = A[i]
      if(A[i] < max1):
        max2 = max(max2,A[i])
  else:
    dic[A[i]] = 1

ans = 0
if(count >= 2):
  if(dic[max1] >= 4):
    ans = max1*max1
  else:
    ans = max1*max2
print(ans)