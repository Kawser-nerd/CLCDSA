s = input()
n = int(input())
ans = 0
anss = []
if n > len(s):
  print(ans)
else:
  for i in range(len(s)-n+1):
    #anss.append(s[i:i+n])
    if s[i:i+n] not in anss:
      anss.append(s[i:i+n])
      ans += 1
  #print(anss)
  print(ans)