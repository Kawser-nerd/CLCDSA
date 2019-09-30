[n,s,t] = [int(i) for i in input().split()]
w = int(input())
cnt = 0
if s <= w and w <= t:
    cnt += 1
for i in range(n-1):
  w += int(input())
  if s <= w and w <= t:
    cnt += 1
  
    
print(cnt)