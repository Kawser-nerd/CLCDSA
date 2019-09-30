h,w = map(int,input().split())
ans = 10**9
ans = min(ans,(h//3+min(1,h%3))*w-(h//3)*w)
ans = min(ans,(w//3+min(1,w%3))*h-(w//3)*h)
for i in range(1,h//2+1):
    s1 = i*w
    s2 = (h-i)*(w//2)
    s3 = (h-i)*(w//2+w%2)
    ans = min(ans,max(s1,s2,s3)-min(s1,s2,s3))
for i in range(1,w//2+1):
    s1 = i*h
    s2 = (w-i)*(h//2)
    s3 = (w-i)*(h//2+h%2)
    ans = min(ans,max(s1,s2,s3)-min(s1,s2,s3))
print(ans)