s = input()
t = int(input())
x = 0
y = 0
q = 0
for i in s:
    if i=="U":
        y += 1
    elif i=="D":
        y -= 1
    elif i=="L":
        x -= 1
    elif i=="R":
        x += 1
    else:
        q += 1
if t == 1:
    print(abs(x)+abs(y)+q)
else:
    d = abs(x)+abs(y)
    if d>q:
        print(d-q)
    else:
        if (d-q)%2==0:
            print(0)
        else:
            print(1)