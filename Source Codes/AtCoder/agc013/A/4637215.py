N = int(input())
A = list(map(int, input().split()))
flag = 0
cnt = 1
for k in range(N-1):
  if (A[k] > A[k+1]):
    flag_tmp = flag
    flag = -1
    if flag_tmp == 1:
      cnt += 1
      flag = 0
  elif (A[k] < A[k+1]):
    flag_tmp = flag
    flag = 1
    if flag_tmp == -1:
      cnt += 1
      flag = 0
print(cnt)