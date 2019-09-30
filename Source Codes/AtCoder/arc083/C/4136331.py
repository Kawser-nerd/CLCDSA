#!/usr/bin/env python3

def main():
    N = int(input())
    P = list(map(int, input().split()))
    P = [0] + P
    X = list(map(int, input().split()))

    Y = [0] * N
    children = [None] * N

    for i in range(N - 1, 0, -1):
        parent = P[i] - 1
        if children[parent] is None:
            children[parent] = []
        children[parent].append(i)


    for i in range(N - 1, -1, -1):
        if not children[i] is None:
            dp = []
            j_max = len(children[i])
            for j in range(j_max + 1):
                dp.append([0] * 5050)
            dp[0][0] = 1
            x_sum, y_sum = 0, 0
            for j in range(j_max):
                c = children[i][j]
                xc, yc = X[c], Y[c]
                x_sum += xc
                y_sum += yc
                for k in range(X[i] + 1):
                    if xc <= k and dp[j][k - xc] == 1:
                        dp[j + 1][k] = 1
                    if yc <= k and dp[j][k - yc] == 1:
                        dp[j + 1][k] = 1
            f = False
            for k in range(X[i], -1, -1):
                if dp[j_max][k] == 1:
                    Y[i] = x_sum + y_sum - k
                    f = True
                    break
            if not f:
                print('IMPOSSIBLE')
                return

    print('POSSIBLE')


if __name__ == '__main__':
    main()