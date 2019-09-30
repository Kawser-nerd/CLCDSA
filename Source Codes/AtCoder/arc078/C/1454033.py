def p(n):
    print("? {}".format(n))
    a=input()
    if a=="Y":
        return 1
    else:
        return 0

ans=p(2)
if ans:
    n=1
    while ans:
        n*=10
        if n==10**10:
            n=10
            break
        ans=p(n)

    n=int(n/10)

else:
    n=1
    while not ans:
        n*=10
        ans=p(2*n)

r=n
l=10*n-1
while r<l:
    m=int((r+l)/2)
    if p(10*m)==1:
        l=m
    else:
        r=m+1

print("! {}".format(l))