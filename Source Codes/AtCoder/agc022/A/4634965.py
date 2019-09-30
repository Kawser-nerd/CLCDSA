import numpy as np
alpha = list('abcdefghijklmnopqrstuvwxyz')
alpha_num = [num for num in range(26)]

d = {char:num for (char, num) in zip(alpha, range(26))}

S = input()
S_num = np.array([d[char] for char in S])
last = S_num[-1]

flag = True

if len(S) < 26:
  S_num.sort()
  for k in range(len(S_num)):
    if S_num[k] != alpha_num[k]:
      print(S + alpha[k])
      flag = False
      break
  if flag:
    print(S + alpha[len(S)])

else:
  for k in reversed(range(1, 26)):
    if S_num[k] > S_num[k-1]:
      A = S_num[k:]
      A = A[A > S_num[k-1]]
      A.sort()
      print(S[:k-1] + alpha[A[0]])
      flag = False
      break
  if flag:
    print(-1)