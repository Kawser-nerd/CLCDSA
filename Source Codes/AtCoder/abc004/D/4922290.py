R, G, B = map(int, input().split())

ans = 10 ** 10
for gl in range(-600, 301):
    gr = gl + G - 1
    temp = 0
    for i in range(gl ,gr + 1):
        temp += abs(i)
    if (R-1) // 2 - 100 < gl:
        if R % 2 == 0:
            for i in range(1, R // 2):
                temp += i * 2
            temp += R // 2
        else:
            for i in range(1, R // 2 + 1):
                temp += i * 2
    else:
        rr = gl - 1
        rl = rr - R + 1
        for i in range(rl, rr + 1):
            temp += abs(i + 100)
    if 100 - (B-1) // 2 > gr:
        if B % 2 == 0:
            for i in range(1, B // 2):
                temp += i * 2
            temp += B // 2
        else:
            for i in range(1, B // 2 + 1):
                temp += i * 2
    else:
        bl = gr + 1
        br = bl + B - 1
        for i in range(bl, br + 1):
            temp += abs(i - 100)
    ans = min(temp, ans)

print(ans)