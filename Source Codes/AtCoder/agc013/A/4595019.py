N = int(input())
a = list(map(int, input().split()))

ans = float('inf')
for way in 1, -1:
    b = 1
    t = a[0]
    for aa in a:
        if way == 1:
            if aa < t:
                b += 1
                way = 0
        elif way == -1:
            if aa > t:
                b += 1
                way = 0
        else:
            if aa < t:
                way = -1
            elif aa == t:
                way = 0
            else:
                # aa > t:
                way = 1
        t = aa
    ans = min(ans, b)
print(ans)