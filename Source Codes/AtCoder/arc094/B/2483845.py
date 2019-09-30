from math import sqrt
q = int(input())
while(q):
    a, b = map(int, input().split())
    c = a * b
    d = int(sqrt(c))
    if(a == b):
        print((d-1) * 2)
    elif(d*d == c):
        print((d-1)*2 - 1)
    elif(d * (d + 1) < c):
        print(d*2 - 1)
    else:
        print((d-1) * 2)
    q -= 1