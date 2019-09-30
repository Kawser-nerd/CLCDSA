n,m = map(int,input().split())
x,y = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

cnt = 0
cnt_a = 0
cnt_b = 0
now = 0

while True :
    flg = True
    for i in range(cnt_a,n):
        if a[i] >= now:
            now = a[i] + x
            cnt_a = i + 1
            flg = False
            break
    
    if flg:
        break
    
    flg = True
    for j in range(cnt_b,m):
        if b[j] >= now:
            now = b[j] + y
            cnt_b = j + 1
            flg = False
            break
    
    if flg:
        break
    else:
        cnt += 1
        
print(cnt)