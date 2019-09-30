#!/usr/bin/python

import collections

rl = raw_input

T = int(rl())
for cas in xrange(1,T+1):
  n = rl().strip().lstrip("0")[::-1]
  cnt = {}
  need = {}
  for i in "0123456789":
    cnt[i] = 0
    need[i] = 0
  for char in n:
    cnt[char] += 1
  used = "".join(i for i in "0123456789" if cnt[i] > 0)
  ans = "Blah"
  for i in xrange(len(n)):
    if ans != "Blah": break
    cnt[n[i]] -= 1
    need[n[i]] += 1
    j = used.find(n[i]) + 1
    while j < len(used):
      if need[used[j]] >= 1:
        c = used[j]
        need[c] -= 1
        if sum(need.values()) <= i:
          ans = n[:i:-1] + c + "0" * (i-sum(need.values()))
          for v in "0123456789":
            ans += v * need[v]
          break
        need[c] += 1
      j += 1
  if ans == "Blah":
    if used[0] == "0":
      used = used[1:]
    ans = used[0] + "0" * (len(n)-sum(need.values())+1)
    need[used[0]] -= 1
    for v in "0123456789":
      ans += v * need[v]
  print "Case #%d:" % cas, ans
  
