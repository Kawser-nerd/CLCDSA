n=int(input())
a=list(map(str,input().split()))
if n%2!=1:
    s=list(reversed(a[1::2]))+a[::2]
else:
    s=list(reversed(a[::2]))+a[1::2]
c=""
for i in range(n):
    c+=s[i]+" "
print(c)