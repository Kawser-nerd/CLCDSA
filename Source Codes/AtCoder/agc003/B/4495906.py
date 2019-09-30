n=int(input())
c=0
d=0
for i in range(n):
    b=int(input())
    if b!=0:
        d+=b
    else:
        c+=d//2
        d=0
print(c+d//2)