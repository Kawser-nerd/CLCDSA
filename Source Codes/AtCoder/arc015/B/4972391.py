d=[0]*6
for i in range(int(input())):
    n,m=map(float,input().split())
    if n>=35:
        d[0]+=1
    elif n>=30:
        d[1]+=1
    elif n>=25:
        d[2]+=1
    if m>=25:
        d[3]+=1
    if m<0:
        if n>=0:
            d[4]+=1
    if n<0:
        d[5]+=1
print(" ".join(str(i)for i in d))