n = int(input())
ans = [-1000] + [0] * n
for i in range(1, n + 1):
  j = i
  while (j % 2 == 0):
    ans[i] += 1
    j /= 2
print(ans.index(max(ans)))