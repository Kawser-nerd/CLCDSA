s = input()
t = int(input())

l = s.count("L")
r = s.count("R")
u = s.count("U")
d = s.count("D")
x = s.count("?")

res = abs(l-r) + abs(u-d)

if t==1:
    print(res+x)
else:
    if res-x < 0:
        if (x-res)%2==1:
            print(1)
        else:
            print(0)
    else:
        print(res-x)