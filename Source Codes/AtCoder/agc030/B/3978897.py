from itertools import accumulate

def burn(L, l_x):
    l_x.append(L)
    l_x.insert(0, 0)
    r_x = list(L - i for i in reversed(l_x))
    return max(burn_in(L, l_x, r_x), burn_in(L, r_x, l_x))


def burn_in(L, l_x, l_l):
    r_x = list(L - i for i in reversed(l_x))
    l = list(accumulate(l_x))
    r = list(accumulate(r_x))
    n_max = len(l_x)
    ret = 0
    for i in range(n_max - 2):
        n_r = (n_max - 2 - i) // 2
        n_l = n_max - n_r - 2
        res = l_x[n_l] if (n_max - i) % 2 == 1 else r_x[n_r]
        can = (l[n_l] - l[i] + r[n_r]) * 2 - res
        ret = max(ret, can)
    return ret


def main():
    L, N = map(int, input().split())
    x = [int(input()) for _ in range(N)]
    print(burn(L, x))
    
if __name__ == "__main__":
    main()