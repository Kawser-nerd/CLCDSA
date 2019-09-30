n = int(input())
ans = 0
for i in range(n):
    a,b,c,d,e = map(int,input().split())
    tmpans = a+b+c+d+ e * 110 / 900
    ans = max(tmpans,ans)
print(ans)