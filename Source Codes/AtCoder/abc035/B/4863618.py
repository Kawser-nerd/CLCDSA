S = input()
T = int(input())

x = 0
y = 0
q = 0

for s in S:
    if s == '?':
        q += 1
    elif s == 'L':
        x -= 1
    elif s == 'R':
        x += 1
    elif s == 'U':
        y -= 1
    elif s == 'D':
        y += 1

if T == 1:
    print(abs(x) + abs(y) + q)
else:
    md = abs(x) + abs(y)
    diff = md - q
    if diff > 0:
        print(diff)
    else:
        print(diff%2)