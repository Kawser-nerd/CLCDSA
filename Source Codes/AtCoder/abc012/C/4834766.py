n=int(input())
a=2025-n
divs=[]
for i in range(1, int(a**0.5)+1):
    if a%i==0:
        divs.append(i)
        if i!=a // i:
            divs.append(a // i)
divs.sort()
for x in divs:
    y=int(a/x)
    if x<10 and y<10:
        print(str(x)+' x '+str(y))