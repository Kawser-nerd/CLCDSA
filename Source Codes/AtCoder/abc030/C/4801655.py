n,m = (int(i) for i in input().split())
x,y = (int(i) for i in input().split())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]

cnta = 0
cntb = 0
now = 0

cnt = 0
while True:
    flg = True
    for i in range(cnta, n):
        if a[i] >= now:
            cnta = i+1
            now = a[i]+x
            flg = False
            break

    if flg:
        break

    flg = True
    for j in range(cntb, m):
        if b[j] >= now:
            cntb = j+1
            now = b[j]+y
            flg = False
            break
    if flg:
        break
    else:
        cnt+=1
    
print(cnt)