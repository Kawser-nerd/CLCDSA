def f(intervals):
    time_used = [0] * 2
    for i in intervals:
        time_used[i[2]] += i[1] - i[0]

    flips = 0
    conseq = []
    for i in range(len(intervals)):
        if intervals[i][2] == intervals[(i+1)% len(intervals)][2]:
            gap = intervals[(i+1)% len(intervals)][0] - intervals[i][1]
            if gap < 0:
                gap += 60 * 24
            conseq.append((gap, intervals[i][2]))
            # conseq.append([intervals[(i+1)%len(intervals)][0] - intervals[i][1])
            # if conseq[-1] < 0:
            #     conseq[-1] += 60 * 24
            flips += 2
        else:
            flips += 1

    conseq.sort()
    for c in conseq:
        time_used[c[1]] += c[0]
        if time_used[c[1]] <= 720:
            flips -= 2
    return flips



T = int(input())
for case in range(1, T+1):
    a,b = map(int, input().split())
    intervals = []
    for i in range(a):
        intervals.append(list(map(int, input().split())))
        intervals[-1].append(0)
    for i in range(b):
        intervals.append(list(map(int, input().split())))
        intervals[-1].append(1)
    intervals.sort()
    ans = f(intervals)
    print("Case #%s: %s" % (case, ans))

