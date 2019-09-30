s = list(input())
t = int(input())
x = 0
y = 0
d = 0
count = 0
for i in range(len(s)):
    if s[i] == 'L':
        x -= 1
    elif s[i] == 'R':
        x += 1
    elif s[i] == 'U':
        y += 1
    elif s[i] == 'D':
        y -= 1
    elif s[i] == '?':
        count += 1
if t == 1:
    print(max(abs(x + count) + abs(y), abs(x) + abs(y + count), abs(x - count) + abs(y), abs(x) + abs(y - count)))
elif t == 2:
    d = abs(x) + abs(y)
    if d > count:
        print(d - count)
    else:
        if (d - count) % 2 == 0:
            print(0)
        else:
            print(1)