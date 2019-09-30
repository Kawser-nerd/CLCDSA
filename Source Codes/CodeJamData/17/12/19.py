import collections

def main():
    for testcase in range(1, int(input()) + 1):
        print(f"Case #{testcase}: {solve()}")

from pprint import pprint
def solve():
    n, p = map(int, input().strip().split())
    rs = list(map(int, input().strip().split()))
    ingredientss = [sorted(map(int, input().split())) for _ in range(n)]

    lows = [0] * n
    higs = [0] * n

    ans = 0
    for serving_size in range(1, 1000005):
        # Readjust step
        one_empty = False
        for i in range(n):
            amounts = ingredientss[i]
            low_ = serving_size*rs[i]*9
            low = low_//10 + (1 if low_%10>0 else 0)
            hig = (serving_size*rs[i]*11)//10

            while higs[i] < p and amounts[higs[i]] <= hig:
                higs[i] += 1
            while lows[i] < p and amounts[lows[i]] < low:
                lows[i] += 1
            if lows[i] >= p:
                return ans
            if lows[i] == higs[i]:
                one_empty = True
                break
        if one_empty:
            # optimiz
            continue
        while True:
            can_ship = all(lows[i] < higs[i] for i in range(n))
            if can_ship:
                ans += 1
                for i in range(n):
                    lows[i] += 1
            else:
                break

    assert False
    return ans


main()
