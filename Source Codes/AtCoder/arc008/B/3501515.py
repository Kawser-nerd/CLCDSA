n,m = map(int,input().split())
s = list(input())
k = list(input())
a = 0
for x in s:
  c = k.count(x)
  if c == 0:
    print(-1)
    exit()
  else:
    a = max(a, (s.count(x)-1)//c+1)
print(a)