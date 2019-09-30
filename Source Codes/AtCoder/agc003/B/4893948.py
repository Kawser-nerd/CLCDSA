n=int(input())
a=[int(input()) for i in range(n)]
b=0
c=0
for i in a:
    if i!=0:
        c+=i
    else:
        b+=c//2
        c=0
print(b+c//2)