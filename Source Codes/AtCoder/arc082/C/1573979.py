from collections import Counter

if __name__ == '__main__':
    N = int(input())
    xy_list = [list(map(int, input().split())) for _ in range(N)]

    modulo_num = 998244353

    duplicate_list = [0] * (N + 1)
    for i in range(N):
        xi, yi = xy_list[i]
        gradient_list = []
        for j in range(N):
            xj, yj = xy_list[j]
            if xi != xj:
                gradient_list.append((yj - yi) / (xj - xi))
            elif yi != yj:
                gradient_list.append(100000)

        counter = Counter(gradient_list)
        for k in counter.values():
            duplicate_list[k + 1] += 1

    ans = pow(2, N, modulo_num)
    ans -= 1
    ans -= N
    for i in range(2, N + 1):
        cnt = duplicate_list[i] // i
        ans -= cnt * (pow(2, i, modulo_num) - i - 1)
    ans = ans % modulo_num
    print(ans)