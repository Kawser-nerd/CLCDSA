N = int(input())
A = list(map(int, input().split()))

ans = 0


def func(A, flag):
    ans = 0
    acc = 0
    for i in range(0, N):
        acc = acc+A[i]
        if i % 2 == flag:
            if acc >= 0:
                ans += 1+acc
                acc = -1
        else:
            if acc <= 0:
                ans += 1-acc
                acc = 1
    return ans


print(min(func(A, 0), func(A, 1)))