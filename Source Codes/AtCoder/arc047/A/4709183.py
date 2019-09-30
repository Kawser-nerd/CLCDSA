N,L = map(int,input().split())
S = input()
t = 1
cr = 0
for c in S:
    if c =='+':
        t += 1
        if t > L:
            cr += 1
            t = 1
    else:
        if c == '-':
            if t>1:
                t -= 1
print(cr)