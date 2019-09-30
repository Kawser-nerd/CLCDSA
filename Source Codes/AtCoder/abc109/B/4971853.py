n = int(input())
w = []
ng = 0

for i in range(n):
    w.append(input())

for i in range(1,n):
    if w[i-1][-1] != w[i][0]:
        ng += 1
        break
    if w.count(w[i-1]) > 1:
        ng += 1
        break

if ng > 0:
    print('No')
else:
    print('Yes')