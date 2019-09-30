n = int(input())
arr = []
for i in range(n):
    arr.append([int(x) for x in input().split()])
for pair in arr:
    a = pair[0]
    b = pair[1]
    t = a*b
    s = int(t ** 0.5)
    if t < 3:
        print(0)
    elif a == b:
        if (a-1) * (b+1) < t:
            print((a-1)*2)
        else:
            print((a-1)*2-1)
    elif s*s == t:
        print((s-1)*2-1)
    elif s*(s+1) < t:
        print(s*2-1)
    else:
        print((s-1)*2)