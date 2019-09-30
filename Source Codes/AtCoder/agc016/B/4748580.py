n  = int(input())
a = list(map(int,input().split()))

y=0

x = max(a)

if max(a)-min(a) >1:
    print("No")

elif max(a) == min(a):
    if max(a)==n-1 or n>=2*max(a):
        print('Yes')
    else:
        print('No')
        
else:
    for i in range(n):
        if a[i] == x:
            y += 1

    if y >=2*(x-(n-y)) and x-n+y >0 and n-y>0:
        print('Yes')
    else:
        print('No')