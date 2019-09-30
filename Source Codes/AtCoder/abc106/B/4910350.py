N = int(input())

if N < 105:
    print(0)
else:
    ans = 1
    for i in range(107, N+1, 1):
        count = 0
        if i % 2 ==0:
            continue
        for j in range(3, i, 2):
            if i % j == 0:
                count += 1
            if count > 6:
                break
        if count == 6:
            ans += 1
    print(ans)