n=int(input())
a=[int(i) for i in input().split()]
leftest=0
cnt=1
for right in range(1,n):
    if a[leftest]>a[right-1]:
        if a[right-1]<a[right]:
            cnt+=1
            leftest=right
    elif a[leftest]<a[right-1]:
        if a[right-1]>a[right]:
            cnt+=1
            leftest=right
print(cnt)