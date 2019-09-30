n = int(input())
a = list(map(int,input().split()))
l = [0]*8
red = 0
for i in range(n):
    if a[i]<=399:
        l[0]+=1
    elif a[i]<=799:
        l[1]+=1
    elif a[i]<=1199:
        l[2]+=1
    elif a[i]<=1599:
        l[3]+=1
    elif a[i]<=1999:
        l[4]+=1
    elif a[i]<=2399:
        l[5]+=1
    elif a[i]<=2799:
        l[6]+=1
    elif a[i]<=3199:
        l[7]+=1
    else:
        red+=1
k = 8-l.count(0)
if k>=1:
    print(k,red+k)
else:
    print(1,red+k)