if __name__ == '__main__':
    N = int(input())
    A = list(map(int, input().split()))

    count = 1

    l = 0
    r = 1
    x = A[0]
    s = A[0]

    while r < N:
        s += A[r]
        x ^= A[r]
        while s != x:
            s -= A[l]
            x ^= A[l]
            l += 1
        r += 1
        count += r-l

    print(count)