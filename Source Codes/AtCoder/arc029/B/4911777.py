import math
a=sorted(list(map(int,input().split())))
for i in range(int(input())):
    b=sorted(list(map(int,input().split())))
    if a[0]<=b[0] and a[1]<=b[1]:
        print("YES")
    else:
        d=90
        e=0
        while d-e>10**(-6):
            l=(d+e)/2
            g=a[1]*math.sin(math.radians(l))+a[0]*math.cos(math.radians(l))
            if g>=b[1]:
                d=l
            else:
                e=l
        else:
            g=a[1]*math.sin(math.radians(e))+a[0]*math.cos(math.radians(e))
            h=a[1]*math.cos(math.radians(e))+a[0]*math.sin(math.radians(e))
            if h<=b[0] and g<=b[1]:
                print("YES")
            else:
                print("NO")