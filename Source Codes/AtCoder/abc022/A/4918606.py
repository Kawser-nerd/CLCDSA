N, S, T = map(int, input().split())
W = int(input())
count = 0
for i in range(N-1):
  if W >= S and T >= W:
    count += 1
    
  tmp = int(input())
  W += tmp
if W >= S and T >= W:
   count += 1
print(count)