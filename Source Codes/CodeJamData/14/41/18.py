for test in range(input()):
    N, X = map(int, raw_input().split())
    S = map(int, raw_input().split())
    S.sort()
    ans = 0
    a, b = 0, N-1
    while a<=b:
        if a<b and S[a]+S[b] <= X:
            a += 1
        b -= 1
        ans += 1
    print "Case #%s: %s" % (test+1, ans)
