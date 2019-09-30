import sys


def solve():
    from collections import defaultdict
    N = int(input())
    jobs = [(0, 0)] + [tuple(map(int, l.split())) for l in sys.stdin]
    timetable = defaultdict(list)
    for i, (start, end) in enumerate(jobs[1:], start=1):
        timetable[start].append((end, i))

    dp = [(0, 0) for _ in [0]*1000001]

    for t in range(999999, -1, -1):
        dp[t] = max(dp[t], dp[t+1])
        for end, i in timetable[t]:
            dp[t] = max(dp[t], (dp[end][0]+1, -i))

    ans_count = dp[0][0]
    ans_list = [-dp[0][1]]
    next_job = -dp[jobs[-dp[0][1]][1]][1]
    while next_job != 0:
        ans_list.append(next_job)
        endtime = jobs[next_job][1]
        next_job = -dp[endtime][1]
    print(ans_count)
    print(*ans_list)


if __name__ == "__main__":
    solve()