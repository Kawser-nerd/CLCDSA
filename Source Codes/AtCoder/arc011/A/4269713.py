s=input().split();m=int(s[0]);n=int(s[1]);su=int(s[2]);ans=su
while su>=m:
    su=su+n-m
    ans+=n
print(ans)