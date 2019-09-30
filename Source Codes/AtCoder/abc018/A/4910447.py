A = [x[1] for x in sorted([[int(input()),i+1] for i in range(3)],reverse=True)]
for i in range(3):
  for j in range(3):
    if A[j] == i+1:
      print(j+1)