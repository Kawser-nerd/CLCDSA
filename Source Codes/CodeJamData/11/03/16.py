lines = open("c2.in", "r").readlines()
num_cases = int(lines[0].strip())
for case_no in range(num_cases):
  n = int(lines[case_no*2+1].strip())
  items = lines[case_no*2+2].strip().split(" ")
  a = []
  for i in range(n):
    a.append(int(items[i]))
  sum = 0
  total = 0
  min = a[0]
  for i in a:
    sum = sum ^ i
    if (i < min): min = i
    total = total + i
  if sum==0:
    print "Case #%d: %d" % (case_no + 1, total - min)
  else:
    print "Case #%d: NO" % (case_no+1)
