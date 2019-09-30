r, c, k = map(int, input().split())
n = int(input())
rlist = [0 for _ in range(r)]
clist = [0 for _ in range(c)]
rclist = []
for _ in range(n):
  _r, _c = map(int, input().split())
  rclist.append((_r-1, _c-1))
  rlist[_r-1] += 1
  clist[_c-1] += 1

rcounter = {}
for _r in rlist:
  if _r in rcounter:
    rcounter[_r] += 1
  else:
    rcounter[_r] = 1

ccounter = {}
for _c in clist:
  if _c in ccounter:
    ccounter[_c] += 1
  else:
    ccounter[_c] = 1

sumk = 0
for _k in range(k+1):
  if _k in rcounter and k - _k in ccounter:
    sumk += rcounter[_k] * ccounter[k-_k]

for _r, _c in rclist:
  if rlist[_r] + clist[_c] == k:
    sumk -= 1
  elif rlist[_r] + clist[_c] == k + 1:
    sumk += 1

print(sumk)