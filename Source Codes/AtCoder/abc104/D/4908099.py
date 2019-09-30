s=input()

a=[1,0,0,0]

for i in range(len(s)):
    c=s[i]
    if c=="A":
        a[1]+=a[0]
    elif c=="B":
        a[2]+=a[1]
    elif c=="C":
        a[3]+=a[2]
    else:
        a=[ a[0]*3 ] + [ a[j+1]*3+a[j] for j in range(3) ]

    a=[a[i]%1000000007 for i in range(4)]

print(a[3])