def solve(N, A):
    """ solve the problem """

    count = 0
    while A:
        size = len(A)
        if size == 1: break
        m = min(A)
        i = A.index(m)
        if i < size - i - 1:
            count += i
        else:
            count += size - i - 1
        A.pop(i)

    return count


def parse():
    """ parse input """

    N = int(input())
    A = list(map(int, input().split(' ')))

    return N, A


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
