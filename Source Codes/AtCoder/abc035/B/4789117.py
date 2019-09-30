s = input()
x,y,q = 0,0,0
for i in s:
    if i == 'L':
        x -= 1
    elif i == 'R':
        x += 1
    elif i == 'U':
        y += 1
    elif i == 'D':
        y -= 1
    else:
        q += 1
t = int(input())
if t == 1:
    print(abs(x)+abs(y)+q)
else:
    if 0 <= (abs(x)+abs(y)-q):
        print(abs(x)+abs(y)-q)
    else:
        print((q - abs(x) - abs(y))%2)