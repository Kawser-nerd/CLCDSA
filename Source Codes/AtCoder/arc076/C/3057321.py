r,c,n = map(int,input().split())
a = [list(map(int, input().split())) for _ in range(n)]
iru = []
for i in range(n):
  if ((a[i][0] == 0 or a[i][0] == r or a[i][1] == 0 or a[i][1] == c) and (a[i][2] == 0 or a[i][2] == r or a[i][3] == 0 or a[i][3] == c)):
    b = a[i]
    b1 = [b[0],b[1]]
    b2 = [b[2],b[3]]
    if b1[0] == 0:
      b1 = b1[1]
    elif b1[1] == c:
      b1 = b1[0] + b1[1]
    elif b1[0] == r:
      b1 = c +r+c -b1[1]
    else:
      b1 = c*2 + r*2 - b1[0]
      
    if b2[0] == 0:
      b2 = b2[1]
    elif b2[1] == c:
      b2 = b2[0] + b2[1]
    elif b2[0] == r:
      b2 = c*2 +r -b2[1]
    else:
      b2 = c*2 + r*2 - b2[0]
    if b1 > b2:
      tmp = b1 +0
      b1 = b2 +0
      b2 = tmp + 0
    iru.append([b1,b2])
iru = sorted(iru)
ato = 0
stack = [r+r+c+c]
flag = 'YES'
for a,b in iru:
  while a >= stack[-1]:
    stack.pop()
 
  if b > stack[-1]:
    flag = 'NO'
    break
  else:
    stack.append(b)
 
print(flag)