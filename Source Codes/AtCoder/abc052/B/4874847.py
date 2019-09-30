n=int(input())
b=0
t=0
for c in input():
    if c == 'I':
        t += 1
    else:
        t -= 1
    if t > b:
        b = t
print(b)