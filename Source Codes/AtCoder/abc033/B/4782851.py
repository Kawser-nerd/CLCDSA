n = int(input())
s = [list(map(str,input().split())) for i in range(n)]
c = 0
d = 0

for i in range(n):
  k = int(s[i][1])
  c += k
  
for i in range(n):
  if int(s[i][1]) > (c//2):
    print(s[i][0])
    d += 1
    break

if d == 0:
  print('atcoder')