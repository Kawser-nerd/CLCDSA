n = int(input())
f = [input().split(' ') for _ in range(n)]
p = [input().split(' ') for _ in range(n)]
res = -10 ** 7 * n
for num in range(1, 1024):
  tmp = 0
  for index in range(0, n):
    tmp += int(p[index][len([True for x in range(0, 10) if f[index][x]=='{:010b}'.format(num)[x]=='1'])])
  res = max(tmp, res)
print(res)