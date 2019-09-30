for tc in range(int(input())):
    r, c = map(int, input().split())
    R = [list(input()) for _ in range(r)]
    for i in range(r):
        for j in range(1, c):
            if R[i][j] == '?':
                R[i][j] = R[i][j - 1]
        for j in range(c - 1, 0, -1):
            if R[i][j - 1] == '?':
                R[i][j - 1] = R[i][j]
    for i in range(1, r):
        if R[i][0] == '?':
            R[i] = R[i - 1]
    for i in range(r - 1, 0, -1):
        if R[i - 1][0] == '?':
            R[i - 1] = R[i]
    print("Case #{}:".format(tc + 1))
    for i in range(r):
        print(''.join(R[i]))
