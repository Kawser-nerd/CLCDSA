n = int(input())
a = list(map(int,input().split()))
res = 100
for i in a:
    cnt = 0
    while i%2==0:
        cnt += 1
        i /= 2
    res = min(res,cnt)
print(res)