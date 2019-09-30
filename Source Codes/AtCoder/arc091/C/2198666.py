import math

j = list(map(int, input().split()))
n = j[0]
a = j[1]
b = j[2]
if (n < a + b - 1) or (n > a * b):
    print(-1)
    exit(0)

ans = list(range(b, 0, -1))
if (n > b):
    counter = len(ans)
    loopcounter = 1
    #sikii = math.ceil((n-b) / (a-1))
    sikii = b
    yoyuu = n - a -b+1
    while (counter < n):
        if (yoyuu >= sikii):
            ans += list(range(counter + sikii, counter, -1))
            yoyuu -= (sikii - 1)
        elif (yoyuu == 0):
            ans += [counter + 1]
        else:
            ans += list(range(counter + yoyuu + 1, counter, -1))
            yoyuu = 0
        loopcounter += 1
        counter = len(ans)

print(' '.join(map(str, ans)))