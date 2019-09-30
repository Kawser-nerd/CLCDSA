a=[]
for i in range(4):
    a.append([j for j in input().split()])

for i in range(2):
    for j in range(4):
        tmp = a[i][j]
        a[i][j] = a[3-i][3-j]
        a[3-i][3-j] = tmp

for i in range(4):
    print(' '.join(a[i]))