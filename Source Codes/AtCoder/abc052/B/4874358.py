n = int(input())
s = input()
x = 0
m = 0
for ch in s:
    if ch == 'I':
        x += 1
        if m < x:
            m = x
    else:
        x -= 1
        if m < x:
            m = x
print(m)