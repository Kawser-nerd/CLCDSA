N = int(input())
A = list(map(int, input().split()))

m = min(A)

while True:
  flag = False
  temp = m
  for i in range(len(A)):
    if A[i] % m > 0 and (A[i] % m) < temp:
      temp = A[i] % m
      flag = True
  if flag == False:
    break
  else:
    m = temp
print(m)