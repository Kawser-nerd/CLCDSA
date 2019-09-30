a,b=map(int,input().split())
d=[input()for i in range(b)]
k=list(input()).index("o")
for i in range(b-1,-1,-1):
    c=0
    if k>1:
        if d[i][k-1]=="-":
            k-=2
            c=1
    if k<2*a-2 and c!=1:
        if d[i][k+1]=="-":
            k+=2
print(k//2+1)