n = int(input())
a = sorted(list(map(int, input().split())),reverse=True)
tot = sum(a)
cnt = 1
for i in a:
  tot -= i
  if i > tot*2:
    break
  cnt += 1
print(cnt)