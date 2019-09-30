N=int(input())
s=list((int(x) for x in input().split()))
c=0
kaisu=1000
for x in s:
    while x%2==0:
        c=c+1
        x=x/2
    if kaisu>=c:
        kaisu=c
    c=0
print(kaisu)