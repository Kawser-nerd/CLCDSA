def calculate(a):
    salt = 0
    tot = 0
    for w, p in a:
        salt += w * p
        tot += w
    return salt / tot


def prioritize(a, target):
    return sorted(a, key=lambda x: x[0]*(x[1]-target), reverse=True)


def search(a, K):
    ng = 100
    ok = 0
    mid = (ok + ng) / 2

    for i in range(100):
        prev = mid

        a = prioritize(a, mid)
        # print(mid, a)
        rho = calculate(a[:K])
        if rho >= mid:
            ok = mid
        else:
            ng = mid
        mid = (ok + ng) / 2
        if abs(mid - prev) < 1e-9:
            break
    return a[:K]


def main():
    N, K = [int(x) for x in input().split()]
    a = []
    for i in range(N):
        w, p = [int(x) for x in input().split()]
        a.append((w, p))
    aa = search(a, K)
    print(calculate(aa))


if __name__ == '__main__':
    main()