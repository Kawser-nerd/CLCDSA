import heapq

if __name__ == '__main__':
    X, Y, Z = list(map(int, input().split()))
    A = []
    B = []
    C = []
    N = X + Y + Z
    for i in range(N):
        tmp_a, tmp_b, tmp_c = list(map(int, input().split()))
        A.append(tmp_a)
        B.append(tmp_b)
        C.append(tmp_c)

    gold_minus_silver = [(a - b, a, b, c) for (a, b, c) in zip(A, B, C)]
    gold_minus_silver.sort()
    # print(gold_minus_silver)

    # ??
    left_side = []
    for i in range(0, Y):
        heapq.heappush(left_side, (
            gold_minus_silver[i][2] - gold_minus_silver[i][3], gold_minus_silver[i][2], gold_minus_silver[i][3]))

    left_max = [0 for i in range(Z + 1)]
    for i in range(0, Y):
        left_max[0] += left_side[i][1]
    left_bronze = []
    for K in range(1, Z + 1):
        heapq.heappush(left_side, (gold_minus_silver[K + Y - 1][2] - gold_minus_silver[K + Y - 1][3],
                                   gold_minus_silver[K + Y - 1][2],
                                   gold_minus_silver[K + Y - 1][3]))
        left_max[K] = left_max[K - 1] + gold_minus_silver[K + Y - 1][2]
        bronze = heapq.heappop(left_side)
        left_max[K] += (bronze[2] - bronze[1])


        # print(left_max)
    # ??
    right_side = []
    for i in range(Y + Z, N):
        heapq.heappush(right_side, (gold_minus_silver[i][1] - gold_minus_silver[i][3], gold_minus_silver[i][1],
                                    gold_minus_silver[i][3]))
    right_max = [0 for i in range(Z + 1)]
    for i in range(0, X):
        right_max[Z] += right_side[i][1]
    right_bronze = []
    for K in range(Z - 1, -1, -1):
        heapq.heappush(right_side, (gold_minus_silver[K + Y][1] - gold_minus_silver[K + Y][3],
                                    gold_minus_silver[K + Y][1],
                                    gold_minus_silver[K + Y][3]))
        right_max[K] = right_max[K + 1] + gold_minus_silver[K + Y][1]
        bronze = heapq.heappop(right_side)
        right_max[K] += (bronze[2] - bronze[1])

    # print(right_max)

    ans = 0
    for i in range(0, Z + 1):
        if ans < left_max[i] + right_max[i]:
            ans = left_max[i] + right_max[i]

    print(ans)