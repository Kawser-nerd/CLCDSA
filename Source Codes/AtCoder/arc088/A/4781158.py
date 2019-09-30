X,Y = map(int,input().split())
ans = 1
while True:
  X *= 2
  if X<=Y:
    ans += 1
  else:
    break
print(ans)