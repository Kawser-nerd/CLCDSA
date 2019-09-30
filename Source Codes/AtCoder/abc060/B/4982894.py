A, B, C = map(int, input().split())
i = 0
while True:
    if (i * B + C) % A == 0:
        print('YES')
        break
    else:
        if i > 0 and (i * B) % A == 0:
            print('NO')
            break
        i += 1