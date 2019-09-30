a,k = map(int,input().split())
if k == 0:
    print(2*10**12-a)
else:
    cnt = 0
    while a < 2*10**12:
        a += 1+k*a
        cnt += 1
    print(cnt)