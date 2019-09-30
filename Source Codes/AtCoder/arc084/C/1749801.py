import math


def main(K, N):
    ans = []

    if K % 2 == 0:
        for i in range(N):
            if i == 0:
                ans.append(K // 2)
            else:
                ans.append(K)
    elif K == 1:
        n2 = math.ceil(N / 2)
        for i in range(n2):
            ans.append(1)
    else:
        K2 = math.ceil(K / 2)
        ans = [K2] * N
        n = N // 2
        for i in range(n):
            if ans[-1] == 1:
                ans.pop()
            else:
                ans[-1] -= 1
                while len(ans) < N:
                    ans.append(K)

    return ' '.join(map(str, ans))


K, N = map(int, input().split())
print(main(K, N))