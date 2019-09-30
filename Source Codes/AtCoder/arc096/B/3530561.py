def main():
    n, c = map(int, input().split())
    x, v = [0] * n, [0] * n
    for i in range(n):
        x[i], v[i] = map(int, input().split())

    ss, sr = [0] * n, [0] * n
    ss[0], sr[0] = v[0] - x[0], v[-1] - c + x[-1]

    mx, mxr = [0] * n, [0] * n
    mx[0], mxr[0] = ss[0], sr[0]

    for i in range(n-1):
        ss[i+1] = ss[i] + v[i+1] - x[i+1] + x[i]
        sr[i+1] = sr[i] + v[n-i-2] - x[n-i-1] + x[n-i-2]
        mx[i+1] = max(mx[i], ss[i+1])
        mxr[i+1] = max(mxr[i], sr[i+1])

    r1, r2 = max(0, mx[n-1]), max(0, mxr[n-1])
    for i in range(n-1):
        r1 = max(r1, sr[i]+mx[n-i-2]-c+x[n-i-1])
        r2 = max(r2, ss[i]+mxr[n-i-2]-x[i])

    print(max(r1, r2))


if __name__ == '__main__':
    main()