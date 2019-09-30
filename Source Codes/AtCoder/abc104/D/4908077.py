s=input()

a=[1,0,0,0]

for i in range(len(s)):
    if s[i]=="A":
        a[1]+=a[0]
    elif s[i]=="B":
        a[2]+=a[1]
    elif s[i]=="C":
        a[3]+=a[2]
    else:
        a=[ a[0]*3 ] + [ a[j]*3+a[j-1] for j in range(1,4) ]

    a=[a[i]%1000000007 for i in range(4)]

print(a[3])