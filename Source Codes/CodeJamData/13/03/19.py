
nums = []
for i in range(1, 10**7 + 5):
  if str(i) == str(i)[::-1]:
    j = i*i
    if str(j) == str(j)[::-1]:
      nums.append(j)

ntest = int(raw_input())
for itc in range(ntest):
  print 'Case #%d:' % (itc+1),
  a, b = map(int, raw_input().split())
  cnt = 0
  for num in nums:
    if a <= num <= b:
      cnt += 1
  print cnt
