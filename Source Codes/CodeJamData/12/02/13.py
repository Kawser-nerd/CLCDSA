
T = input()
for t in range(1,T+1):
    inp = raw_input().split()
    [N, S, p] = [int(s) for s in inp[0:3]]
    ts = [int(s) for s in inp[3:]]

    min_without_surprise = p + 2*max(p-1,0)
    min_with_surprise = p + 2*max(p-2,0)

    without_surprise = 0
    with_surprise = 0
    for ti in ts:
        if ti >= min_without_surprise:
            without_surprise += 1
        elif ti >= min_with_surprise:
            with_surprise += 1

    answer = without_surprise + min(with_surprise, S)

    print "Case #" + str(t) + ": " + str(answer)
