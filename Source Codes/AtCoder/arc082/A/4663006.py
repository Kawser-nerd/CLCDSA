from collections import Counter
n = int(input())
d = Counter(map(int, input().split()))
cnt = 0
for i in d:
  new = d.get(i,0) + d.get(i-1,0) + d.get(i+1,0)
  if new > cnt:
    cnt = new
print(cnt)