# dolphinigle
# GCJ 2013 1B
# 4 May 2013

ntest = int(raw_input())
for itc in range(ntest):
  print 'Case #%d:' % (itc+1),
  my_mote, n = map(int, raw_input().split())
  motes = sorted(map(int, raw_input().split()))
  if my_mote == 1:
    print n
    continue
  best_answer = n
  my_answer = 0
  for index, i in enumerate(motes):
    if i < my_mote:
      my_mote += i
      continue
    # maybe stop here?
    best_answer = min([best_answer, my_answer + n - index])
    while my_mote <= i:
      my_mote += my_mote - 1
      my_answer += 1
    my_mote += i
  best_answer = min([best_answer, my_answer])
  print best_answer
