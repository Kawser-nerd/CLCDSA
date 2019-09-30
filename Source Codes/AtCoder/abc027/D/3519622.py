s = input()
n = len(s)
a = [[0,0] for i in range(n)]
for i,j in enumerate(s):
  a[i][0]  += a[i-1][0]
  a[i][1]  += a[i-1][1]
  if j == "+":
    a[i][0] += 1
  if j == "-":
    a[i][1] += 1
b = [0] * n
for i in range(n):
  b[i] = (a[-1][0] - a[i][0]) - (a[-1][1] - a[i][1])
ans = []
for i,j in enumerate(s):
  if j == "M":
    ans.append(b[i])
ans.sort()
ans1 = ans[:len(ans)//2]
ans2 = ans[len(ans)//2:]
print(sum(ans2)-sum(ans1))