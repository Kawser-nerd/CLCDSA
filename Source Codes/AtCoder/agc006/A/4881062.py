n=int(input())
s=input()
t=input()
ls=len(s)
lt=len(t)
ans=s+t
for i in range(n):
    if s[i:]==t[:ls-i]:
        ans=s+t[ls-i:]
        break
print(len(ans))