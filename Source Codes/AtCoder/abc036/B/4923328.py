import copy
n=int(input())
p = [["a"]*(n)]*(n)
q = [["a"]*(n)]*(n)
for i in range(n):
  p[i] = list(input())
for i in range(n):
  for j in range(n):
    q[i][j]  =  p[n-1-j][i]
   # q[j][n-1-i] =p[i][j]
"""
for i in range(n):
  for j in range(n):
    print(q[i][j], end="")
    if j == n-1:
      print("")
"""
for i in range(n):
  for j in range(n):
    print(p[n-1-j][i], end="")
    if j == n-1:
      print("")