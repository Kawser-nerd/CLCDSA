y,m,d=map(int,input().split("/"))
s=[31,28,31,30,31,30,31,31,30,31,30,31]
if m==2:
    if y%4==0:
        if y%100==0:
            if y%400==0:
                s[1]+=1
        else:
            s[1]+=1
for i in range(m,13):
    if y%i==0:
        for j in range((1 if i!=m else d),s[i-1]+1):
            if (y//i)%j==0:
                print(str(y)+"/"+"0"*(2-len(str(i)))+str(i)+"/"+"0"*(2-len(str(j)))+str(j))
                exit()
else:
    print(str(y+1)+"/01/01")