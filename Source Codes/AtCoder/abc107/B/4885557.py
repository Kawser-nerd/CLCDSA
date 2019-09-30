H,W=map(int,input().split())

a=[input() for i in range(H)]

while True:
    b=a
    for i in range(len(a)-1,-1,-1):
        if not "#" in a[i]: a.pop(i)   

    for j in range(len(a[0])-1,-1,-1):
        if all(a[i][j]=="." for i in range(len(a))):
            for i in range(len(a)):
                a[i]=a[i][:j]+a[i][j+1:]


    if b==a: break

for i in range(len(a)): print(a[i])