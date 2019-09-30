from collections import defaultdict
T = int(input())
for tc in range(T):
    R, N, M, K = map(int, input().split())
    def factor(p):
        fac = defaultdict(int)
        for d in range(2, M + 1):
            while p % d == 0:
                p /= d
                fac[d] += 1
        return fac
    print("Case #{}:".format(tc + 1))
    for r in range(R):
        prod = map(int, input().split())
        factors = [factor(p) for p in prod]
        numtimes = defaultdict(int)
        for k in range(K):
            for d in range(2, M + 1):
                numtimes[d] = max(numtimes[d], factors[k][d])
        ans = ""
        ans += '3' * numtimes[3] + '5' * numtimes[5]
        if 3 - len(ans) == 1:
            if numtimes[2] == 1:
                ans += '2'
            else:
                ans += '4'
        elif 3 - len(ans) == 2:
            if numtimes[2] == 4:
                ans += '44'
            elif numtimes[2] == 3:
                ans += '42'
            else:
                ans += '22'
        else:
            has2 = any(factors[k][2] % 2 == 1 for k in range(K))
            if has2:
                ans += '2'
                numtimes[2] -= 1
            num4 = numtimes[2] // 2
            if numtimes[2] % 2 == 1:
                ans += '2'
            ans += '4' * num4
        ans += '2' * (3 - len(ans))
        print(ans)
