lines = open("d2.in", "r").readlines()
num_cases = int(lines[0].strip())
for case_no in range(num_cases):
  n = int(lines[case_no*2+1].strip())
  items = lines[case_no*2+2].strip().split(" ")
  a = []
  for i in range(n):
    a.append(int(items[i]) - 1)
  ans = 0
  for i in range(n):
    if (a[i] != i): ans = ans + 1
  print "Case #%d: %d" % (case_no+1, ans)

