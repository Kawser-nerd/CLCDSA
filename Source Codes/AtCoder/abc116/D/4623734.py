# /usr/bin/python
# -*- coding: utf-8 -*-
import sys


n,k = map(int, input().split())
td_mx = {}
td = []
for _ in range(n):
  t,d = map(int, input().split())
  if t not in td_mx:
    td_mx[t] = d
  elif td_mx[t] < d:
    td.append(td_mx[t])
    td_mx[t] = d
  else:
    td.append(d)
td = sorted(td, key=lambda x:-x)
td_mx = sorted(td_mx.values(), key=lambda x:-x)

# td,td_mx ????????
csum = [0]
csum_mx = [0]
for i in range(len(td)):
  csum.append(csum[-1] + td[i])
for i in range(len(td_mx)):
  csum_mx.append(csum_mx[-1] + td_mx[i])


# 1~k????? ????????
ans = 0
for i in range(1,k+1):
  if i <= len(csum_mx)-1 and k-i <= len(csum)-1:
    ans = max(ans, csum_mx[i] + csum[k-i] + i*i)
print(ans)