n=int(input())
s=["1","2","3","4","5","6"]
n=n%30
for i in range(n):
    x=s[i%5]
    s[i%5]=s[i%5+1]
    s[i%5+1]=x
ans=""
for x in s:
    ans+=x
print(ans)