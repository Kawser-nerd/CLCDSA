N = int(input())
numbers = list(map(int, input().split()))
 
sums = [0] * (N + 1)
for i in range(len(numbers)):
  sums[i] = sums[i-1]+numbers[i]
sums = sorted(sums)

temp = ""
count = 0
res = 0
for i in range(len(sums)):
  if temp == sums[i]:
    count += 1
  else:
    if count >= 2:
      c = 1
      for j in range(count-1, count+1):
        c *= j
      res += c/2
    count = 1
    temp = sums[i]
    
if count >= 2:
  c = 1
  for i in range(count-1, count+1):
    c *= i
  res += c/2
    
print(int(res))