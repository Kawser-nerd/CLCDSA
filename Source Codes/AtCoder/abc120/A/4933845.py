a=list(map(int, input().split()))
 
if a[1]/a[0]>=a[2]:
    print(a[2])
else:
    print(a[1]//a[0])