a, b = map(int, input().split())
s = input()
cnt = 1; ans=0
for x in s:
    if x == '+':
        cnt+=1
    else:
        cnt-=1
    if cnt > b:
        cnt=1
        ans+=1
print(ans)