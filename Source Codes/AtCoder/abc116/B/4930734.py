x=int(input())
L=[x]
n=1
while 1:
    n+=1
    x = 3*x+1 if x%2 else x//2
    if x in L:
        print(n)
        break
    else:
        L.append(x)