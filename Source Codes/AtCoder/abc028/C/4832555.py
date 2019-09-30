ABCDE = list(map(int,input().rstrip().split()))

total_list = []
for i in ABCDE:
  for j in ABCDE:
    if i == j:
      continue
    for k in ABCDE:
      if j == k or i == k:
        continue
      else:
        total = i+j+k
        if not total in total_list:
          total_list.append(total)
total_list.sort()
print(total_list[-3])