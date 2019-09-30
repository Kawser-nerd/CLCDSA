n,a,b=[int(i) for i in input().split()]
num=n%(a+b)
if num==0:
    print("Bug")
else:
    print("Ant" if num<=a else "Bug")