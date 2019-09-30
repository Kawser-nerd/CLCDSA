n = int(input())
a = list(map(int,input().split()))
res = 0
for i in a:
    t = i
    cnt = 0
    while t%2==0 or (t-2)%3==0:
        t -= 1
        cnt += 1
    res += cnt
print(res)