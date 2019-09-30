n = int(input())
Aa = list(map(int,input().split()))
ans = 0
for i in range(len(Aa)):
    while True:
        if Aa[i]%2==0 or Aa[i]%3==2:
            Aa[i]-=1
            ans+=1
        else:
            break
print(ans)