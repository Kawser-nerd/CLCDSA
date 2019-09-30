s=input()

a=[1,0,0,0]

for i in range(len(s)):
    c=s[i]
    if c=="A":
        a[1]=(a[1]+a[0])%1000000007
    elif c=="B":
        a[2]=(a[2]+a[1])%1000000007
    elif c=="C":
        a[3]=(a[3]+a[2])%1000000007
    elif c=="?":
        tmp=[a[i] for i in range(4)]
        a[0]=tmp[0]*3
        for j in range(3):
            a[j+1]=tmp[j+1]*3+tmp[j]
        a=list(map(lambda x: x%1000000007,a))

    
print(a[3]%1000000007)