def solve(n, a_list):
    numbers_map = {1: 2, 2: 5, 3: 5, 4: 4, 5: 5, 6: 6, 7: 3, 8: 7, 9: 6}
    usable_map = {}
    for a in a_list:
        usable_map[a] = numbers_map[a]

    # 1-origin ????? -inf????
    inf = 1000
    dp = [0] + [-inf for _ in range(n)]
    for value in usable_map.values():
        if value <= n:
            dp[value] = 1

    # time O(NM)
    for cost in range(1, n + 1):
        for value in usable_map.values():
            if cost - value < 0 or dp[cost - value] == 0:
                continue
            dp[cost] = max(
                dp[cost],
                dp[cost - value] + 1
            )

    # time O(M log(M))
    buff = []
    digit = n
    reverse_usable_list = sorted(usable_map.items(), reverse=True)
    while True:
        for num, value in reverse_usable_list:
            if digit - value < 0 or dp[digit] - 1 != dp[digit - value]:
                continue
            buff.append(str(num))
            digit -= value
            break
        if digit <= 0:
            break

    return "".join(buff)


def main():
    n, m = map(int, input().split())
    a_list = list(map(int, input().split()))

    ans = solve(n, a_list)
    print(ans)


main()