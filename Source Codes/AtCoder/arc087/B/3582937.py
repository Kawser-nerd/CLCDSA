s = input() + 'T'
x, y = [int(i) for i in input().split()]

dire = True
xi = []
yi = []
ctr = 0
for i in range(len(s)):
    if s[i] == 'F':
        ctr += 1
        continue
    if dire:
        xi.append(ctr)
    else:
        yi.append(ctr)
    ctr = 0
    dire = not dire
ans = 'Yes'
X = (sum(xi)-x)//2
x0 = xi.pop(0)
Hx = {0: True}
for i in xi:
    for j in Hx.copy().keys():
        Hx[j+i] = True
Y = (sum(yi)-y)//2
Hy = {0: True}
for i in yi:
    for j in Hy.copy().keys():
        Hy[j+i] = True
        
if (x0+sum(xi)-x)%2 != 0 or (sum(yi)-y)%2 != 0:
    ans = 'No'
if not Hx.get(X, False) or not Hy.get(Y, False):
    ans = 'No'
print(ans)