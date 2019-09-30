v = [0]*9
n = int(input())
a = list(map(int,input().split()))
for i in a:
  idx = i//400
  if idx >= 8: idx = 8
  v[idx] += 1
r = 0
for i in range(8):
  if v[i] >= 1: r+= 1
print(max(1,r), r+v[8])