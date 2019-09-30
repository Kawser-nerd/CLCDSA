a,b,*c=open(0).read().split()
if int(a)+int(b)-1==sum(i.count("#") for i in c):
    print("Possible")
else:
    print("Impossible")