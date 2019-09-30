n=int(input());a,b,c,d,e,f=0,0,0,0,0,0
for i in range(0,n):
    s=input().split()
    if float(s[0])>=35:
        a+=1
    if float(s[0])<35 and float(s[0])>=30:
        b+=1
    if float(s[0])>=25 and float(s[0])<30:
        c+=1
    if float(s[1])>=25:
        d+=1
    if float(s[0])>=0 and float(s[1])<0:
        e+=1
    if float(s[0])<0:
        f+=1
print(a,b,c,d,e,f)