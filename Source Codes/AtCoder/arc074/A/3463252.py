a,b=map(int, input().split())
ans=a*b
if a%3==0 or b%3==0:ans=0 
if a>2:ans=min(ans,a)
if b>2:ans=min(ans,b)
for i in range(1,a):
    m=max(abs(b*i-b//2*(a-i)),abs(b//2*(a-i)-(-(-b//2)*(a-i))),abs(b*i-(-(-b//2)*(a-i))))
    ans=min(m,ans)
for i in range(1,b):
    m=max(abs(a*i-a//2*(b-i)),abs(a//2*(b-i)-(-(-a//2)*(b-i))),abs(a*i-(-(-a//2)*(b-i))))
    ans=min(m,ans)
print(ans)