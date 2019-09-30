m = list(map(int, input().split()))
a = m[0]
b = m[1]
c = m[2]

if(b >= a * c):
    print(c)
else:
    print(b // a)