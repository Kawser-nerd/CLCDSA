a,b = input().split()
ans = int(a)-int(b)
x = '9'+a[1]+a[2]
y = a[0]+'9'+a[2]
z = a[0]+a[1]+'9'
ans = max(ans,int(x)-int(b),int(y)-int(b),int(z)-int(b))
d = '1'+ b[1]+b[2]
e = b[0]+'0'+b[2]
f = b[0]+b[1]+'0'
ans = max(ans,int(a)-int(d),int(a)-int(e),int(a)-int(f))
print(ans)