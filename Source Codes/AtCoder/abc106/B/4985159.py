N = int(input())
ans = 0
if N<105:
  ans = 0
else:
  for i in range(105,N+1,2):
    cnt = 0
    for j in range(1,N+1,2):
      if i%j == 0:
        cnt += 1
        if cnt == 8:
          ans += 1
print(ans)