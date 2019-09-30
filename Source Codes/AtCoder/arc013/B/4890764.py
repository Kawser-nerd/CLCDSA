d,e,f=0,0,0
for i in range(int(input())):
    a=sorted(list(map(int,input().split())))
    d,e,f=max(d,a[0]),max(e,a[1]),max(f,a[2])
print(d*e*f)