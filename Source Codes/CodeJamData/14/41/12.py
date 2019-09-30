n = int(raw_input())
for i in range(n):
  [N,X] = [int(x) for x in raw_input().split()]
  disks = [int(x) for x in raw_input().split()]
  disks.sort()
  answer = 0
  while disks:
    if len(disks) == 1:
      answer+=1
      disks.pop()
    else:
      if disks[0] + disks[-1] <= X:
        answer += 1
        disks.pop(0)
        disks.pop()
      else:
        answer += 1
        disks.pop()
  print "Case #%d: %d"%(i+1, answer)
