T = input()
count, temp = [], 0
AGCT = ['A', 'G', 'C', 'T']
for i in T:
  if (i in AGCT) == True:
    temp += 1
  else:
    count.append(temp)
    temp = 0
count.append(temp)
print(max(count))