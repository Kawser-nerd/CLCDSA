N, x = map(int, input().split(" "))
A = list(map(int, input().split(" ")))
A.sort()
 
ans = 0
for a in A:
  if a <= x:
    ans += 1
    x -= a
  else:
    x -= a
    break
if x > 0: ans -= 1
    
print(ans)