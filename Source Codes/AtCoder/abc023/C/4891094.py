from collections import Counter
def solve():
  r,c,k = (int(i) for i in input().split())
  n = int(input())
  rc = []
  rowquery = [0]*r
  columnquery = [0]*c
  for i in range(n):
    r,c = (int(i) for i in input().split())
    rowquery[r-1] += 1
    columnquery[c-1] += 1
    rc.append((r,c))
  #print(Counter(rowquery))
  #print(columnquery)
  R = Counter(rowquery)
  C = Counter(columnquery)
  ans = 0
  for i in R.keys():
    #print(i)
    ans += R[i]*C[k-i]
    
  #?????????2??????????????????
  for i,j in rc:
    if rowquery[i-1]+columnquery[j-1] == k: ans -= 1
    elif rowquery[i-1]+columnquery[j-1] == k+1: ans += 1
  print(ans)
solve()