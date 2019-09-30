import collections
n= int(input())
a = list(int(i) for i in input().split())
c = collections.Counter(a)
a2 = list(set(a))
ans = 0
for i in a2:
  tmp = c[i]
  if tmp <i:
   ans += tmp
  else:
   ans += (tmp-i)
print(ans)