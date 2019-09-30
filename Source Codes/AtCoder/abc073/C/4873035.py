N = int(input())
dic = {}
for i in range(N):
  a = int(input())
  if(a in dic):
    dic[a] += 1
  else:
    dic[a] = 1

ans = 0
for k, v in sorted(dic.items()):
  if(v%2 == 1):
    ans += 1
print(ans)