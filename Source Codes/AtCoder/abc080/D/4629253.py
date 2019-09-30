def recording(N: int, C: int, info: list) -> int:
    _, max_time, _ = max(info, key=lambda x: x[1])
    max_time = 2*max_time

    # ????????????????????????????
    # recorders ????????S-0.5 ?????????
    # 2*(max_time) ??????????
    recorders = [[0] * C for _ in range(max_time + 1)]

    # ??????? +1 ?????? -1 ??????????
    # ???????????????????? 1 ??????
    # ??? 0 ??????????
    for s, t, ch in info:
        recorders[2*s-1][ch-1] += 1
        recorders[2*t][ch-1] -= 1

    # ???????
    for t in range(max_time):
        for ch in range(C):
            recorders[t+1][ch] += recorders[t][ch]

    # ????????????????????????
    return max(
        sum(used > 0 for used in recorders[t])
        for t in range(max_time+1))


if __name__ == "__main__":
    N = 0
    N, C = map(int, input().split())
    info = [tuple(map(int, input().split())) for _ in range(N)]
    ans = recording(N, C, info)
    print(ans)