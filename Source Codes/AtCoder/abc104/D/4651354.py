a=[1]+[0]*4
m=10**9+7
for s in input():
 i=ord(s)-64
 if i>0:a[i]+=a[i-1]
 else:a=[a[i]*3%m+a[i-1]for i in range(4)]+[0]
print(a[3]%m)