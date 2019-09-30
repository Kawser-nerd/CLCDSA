def dp_table(*counts):  # dp[x][y]???????? dp_table(x????,y????)
    if counts:
        return [dp_table(*counts[1:]) for _ in range(counts[0])]
    else:
        return None


def solve(dp, N: str, index: int = 0, tight: bool = True, amount_1: int = 0):
    if len(N) == index:
        return amount_1
    elif dp[index][tight][amount_1] is not None:
        return dp[index][tight][amount_1]
    else:
        if tight:
            for_max = int(N[index])+1
        else:
            for_max = 10
        return_ = 0
        for i in range(for_max):
            return_ += solve(dp, N, index + 1, tight and i ==
                             int(N[index]), amount_1+1 if i == 1 else amount_1)
        # print(index, return_)
        dp[index][tight][amount_1] = return_
        return return_


def main():
    N = int(input())
    digit_N = str(N)
    dp = dp_table(len(digit_N) + 1, 2, len(digit_N) + 1)
    print(solve(dp, digit_N))


if __name__ == '__main__':
    main()