N = int(input())
T = [[int(_) for _ in input().split()] for i in range(N)]

inf = 0
sup = max([h + (N - 1) * s for h, s in T])


def check(x):
    for idx, time_limit in enumerate(sorted([(x - h) // s for h, s in T])):
        if time_limit < idx:
            return False

    return True


while sup - inf > 1:
    mid = (sup + inf) // 2

    if check(mid):
        sup = mid
    else:
        inf = mid

print(sup)