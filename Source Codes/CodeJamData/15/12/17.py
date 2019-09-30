#!/bin/env python

cases = int(raw_input())

for i in xrange(cases):
  barber_count, place = map(int, raw_input().split())
  barbers = map(int, raw_input().split())
  def elapsed(n):
  	return sum((n / b + 1) for b in barbers)

  start = 0
  end = 1
  while elapsed(end) <= place:
  	end *= 2
  while start != end:
    mid = (start + end + 1) / 2
    if elapsed(mid) > place - 1:
  	  end = mid - 1
    else:
      start = mid


  done = place - elapsed(end)
  avail = [b for b in  xrange(len(barbers)) if (end + 1) % barbers[b] == 0]
  #print (done, end, place, elapsed(end))
  ind = avail[done-1] + 1
  

  print "Case #{}: {}".format(i+1, ind)