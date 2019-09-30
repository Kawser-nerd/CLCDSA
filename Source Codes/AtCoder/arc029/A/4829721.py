n=int(input())
t=[]
for i in range(n):
    t.append(int(input()))

def base(X, n):
    X_dumy = X
    out = ''
    while X_dumy>0:
        out = str(X_dumy%n)+out
        X_dumy = int(X_dumy/n)
    return out
ans=1000000000
for i in range(2**n):
    x=0
    y=0
    b=base(i,2).rjust(n,"0")
    for j in range(n):
        if b[j]=="0":
            x+=t[j]
        else:
            y+=t[j]
    ans=min(ans,max(x,y))

print(ans)