def mod(k: int, c: int) -> int:
    ret = 0
    for n in str(k):
        ret = (ret * 10 + int(n)) % c
    return ret


def strange_dict(N: int, a: int, k: int, B: list) -> int:
    route = []
    idx = a-1

    while idx not in route:
        route.append(idx)
        idx = B[idx] - 1
    cycle_start = idx

    if k < len(route):
        return route[k] + 1

    # if d[idx] >= 0:
    T = route.index(cycle_start)  # ?????????????
    C = len(route) - T            # ??????

    return route[(k - T) % C + T] + 1


if __name__ == "__main__":
    N, a = map(int, input().split())
    k = int(input())
    B = [int(s) for s in input().split()]
    ans = strange_dict(N, a, k, B)
    print(ans)