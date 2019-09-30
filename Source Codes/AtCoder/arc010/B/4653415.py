l = [31,29,31,30,31,30,31,31,30,31,30,31]
d = [0]*12
for i in range(11):
  d[i+1] = d[i] +l[i]
cal = [0]*367
for i in range(6,367,7):
    cal[i] = 1
    cal[i+1] = 1
cal[0] = 1
n = int(input())
for _ in range(n):
  m,w = map(int, input().split("/"))
  while cal[d[m-1]+w-1] == 1:
    w += 1
  cal[d[m-1]+w-1] = 1
  cal[-1] = 0
cnt = 0
ans = 2
b = 0
for i in range(367):
  if cal[i] == 1:
    cnt += 1
    b = 1
  elif b and cal[i]==0:
    if ans < cnt:
      ans = cnt
    cnt,b = 0,0
print(ans)