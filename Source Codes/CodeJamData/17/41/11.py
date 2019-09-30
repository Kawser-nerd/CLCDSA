import sys

memo = {}

def solve_4(mod_1, mod_2, mod_3):
    if (mod_1, mod_2, mod_3) in memo:
        return memo[(mod_1, mod_2, mod_3)]
    ans = 0
    if mod_1 >= 4:
        ans = max(ans, 1 + solve_4(mod_1 - 4, mod_2, mod_3))
    if mod_1 >= 2 and mod_2 >= 1:
        ans = max(ans, 1 + solve_4(mod_1 - 2, mod_2 - 1, mod_3))
    if mod_1 >= 1 and mod_3 >= 1:
        ans = max(ans, 1 + solve_4(mod_1 - 1, mod_2, mod_3 - 1))
    if mod_2 >= 2:
        ans = max(ans, 1 + solve_4(mod_1, mod_2 - 2, mod_3))
    if mod_2 >= 1 and mod_3 >= 2:
        ans = max(ans, 1 + solve_4(mod_1, mod_2 - 1, mod_3 - 2))
    if mod_3 >= 4:
        ans = max(ans, 1 + solve_4(mod_1, mod_2, mod_3 - 4))
    if ans == 0 and max(mod_1, mod_2, mod_3) > 0:
        ans = 1
    memo[(mod_1, mod_2, mod_3)] = ans
    return ans


def solve():
    n, p = map(int, raw_input().strip().split())
    g = map(int, raw_input().strip().split())
    mod_0 = len(filter(lambda x: x % p == 0, g))
    mod_1 = len(filter(lambda x: x % p == 1, g))
    mod_2 = len(filter(lambda x: x % p == 2, g))
    mod_3 = len(filter(lambda x: x % p == 3, g))
    if p == 2:
        print mod_0 + (mod_1 + 1) / 2
    elif p == 3:
        ans = mod_0
        t = min(mod_1, mod_2)
        mod_1 -= t
        mod_2 -= t
        ans += t
        ans += (mod_1 + 2) / 3
        ans += (mod_2 + 2) / 3
        print ans
    elif p == 4:
        print mod_0 + solve_4(mod_1, mod_2, mod_3)



if __name__ == '__main__':
    T = int(raw_input())
    for case_idx in xrange(1, T+1):
        sys.stdout.write("Case #{}: ".format(case_idx))
        solve()
