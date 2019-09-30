n,m = map(int, input().split())
l = [tuple(map(int, input().split())) for _ in range(m)]
l.sort(key=lambda x:x[1])
dec = 0
cur = 0
for i in l:
  if i[0] < cur <= i[1]:
    continue
  else:
    dec += 1
    cur = i[1]
print(dec)