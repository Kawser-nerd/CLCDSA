a,b,c,d,e,f=map(int,input().split())
x=1
y=-1
for i in range(0,f+1,a*100):
    for j in range(0,f+1-i,b*100):
        s=min(f-i-j,(i+j)*e//100)
        if i+j==0:
            continue
        else:
            for p in range(0,s+1,c):
                for q in range(0,s+1-p,d):
                    if y/x<=(p+q)/(i+j):
                        y=p+q
                        x=i+j
print(x+y,y)