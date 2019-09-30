from collections import Counter
n,m = map(int, input().split())
d1 = Counter(input())
d2 = Counter(input())
m = 0
for i in d1:
  if i not in d2:
    print(-1)
    exit()
  else:
    a = (d1[i]-1)//d2[i] + 1
    if a > m:
      m = a
print(m)