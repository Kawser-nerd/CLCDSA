n=int(input())
s=input().split()
l=[int(s[i]) for i in range(n)]
l.sort()
if l[0]==l[-1]:
    if l[0]<=n//2 or l[0]==n-1:
        print("Yes")
    else:
        print("No")
elif l[-1]-l[0]>1:
    print("No")
else:
    a=l.count(l[0])
    b=l.count(l[-1])
    if a+1<=l[-1]<=a+b//2:
        print("Yes")
    else:
        print("No")