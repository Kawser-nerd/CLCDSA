cookie = list(map(int, input().split()))

cookie.sort()

count = 0
if cookie[0] == cookie[2] and cookie[0] % 2 == 0:
    print(-1)
    exit()
    
while cookie[2] - cookie[0] > 0:
    if cookie[0] % 2 == 1 or cookie[1] % 2 == 1 or cookie[2] % 2 == 1:
        print(count)
        exit()
    if cookie[0] == cookie[2]:
        print(-1)
        exit()
    count += 1
    a = (cookie[1] + cookie[2]) // 2
    b = (cookie[2] + cookie[0]) // 2
    c = (cookie[0] + cookie[1]) // 2
    cookie[0] = a
    cookie[1] = b
    cookie[2] = c
    cookie.sort()

print(count)