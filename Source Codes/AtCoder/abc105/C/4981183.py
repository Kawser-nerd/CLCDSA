N = int(input())


def convert(n):
    result = []
    while True:
        a = n // 2
        b = n % 2
        result.insert(0, b)
        if a == 0:
            break
        else:
            n = a
    return result


def sigma_1(m):
    Sum = 0
    for i in range(m):
        Sum += 2**i
    return Sum


def sigma_2(m):
    Sum = 0
    for i in range(m):
        Sum += 2**(2*i)
    return Sum


def sigma_3(m):
    Sum = 0
    for i in range(1, m+1):
        Sum += 2**(2*i-1)
    return Sum


if 0 <= N <= 1:
    print(N)
elif N > 1:
    digit = 3  # N >= 2
    while True:
        if 1 + sigma_2(digit//2) <= N <= sigma_2(digit//2+1):
            break
        digit += 2
    ans = N-(1+sigma_2(digit//2)) + 2**(digit-1)
    ans = convert(ans)
    idx = 0
    for k in ans:
        if idx % 2:
            if k == 0:
                ans[idx] = 1
            else:
                ans[idx] = 0
        idx += 1
    for j in ans:
        print(j, end="")
else:
    N *= -1
    digit = 2
    while True:
        if 1 + sigma_3(digit//2-1) <= N <= sigma_3(digit//2):
            break
        digit += 2
    ans = N-(1+sigma_3(digit//2-1)) + 2**(digit-1)
    ans = convert(ans)
    idx = 0
    for k in ans:
        if idx % 2:
            if k == 0:
                ans[idx] = 1
            else:
                ans[idx] = 0
        idx += 1
    for j in ans:
        print(j, end="")