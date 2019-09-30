s = input()
t= int(input())

n=s.count('?')
u=s.count("U")
d=s.count("D")
l=s.count("L")
r=s.count("R")

x=abs(l-r)
y = abs(u-d)
if t==1:
    print(x+y+n)
else:
    if x+y<n and (n-(x+y))%2==0:
        print(0)
        exit()
    elif x+y<n and (n-(x+y))%2==1:
        print(1)
        exit()


    else:
        print(x+y-n)