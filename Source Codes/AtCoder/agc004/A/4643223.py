a,b,c = map(int,input().split())
d = sorted([a,b,c])
if (a%2 + b%2 + c%2) == 3:
    print(d[0]*d[1])
else:
    print(0)