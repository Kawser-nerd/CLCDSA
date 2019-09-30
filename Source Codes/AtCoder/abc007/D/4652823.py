def dp_table(*counts):
    if counts:
        return [dp_table(*counts[1:]) for _ in range(counts[0])]
    else:
        return None


def solve(dp, S: str, index: int = 0, tight: bool = True, has4or9: bool = False):
    # print(dp)
    # print(index)
    if len(S) == index:
        return has4or9  # ???????????4,9?????1,?????0???
    elif dp[index][tight][has4or9] is not None:
        return dp[index][tight][has4or9]
    else:
        if tight:
            for_max = int(S[index])+1
        else:
            for_max = 10
        return_ = 0
        for i in range(for_max):
            return_ += solve(dp, S, index + 1, tight and i ==
                             int(S[index]),  has4or9 or str(i) in "49")
        #print(index, return_)
        dp[index][tight][has4or9] = return_
        return return_


# [A,B]????????[0,B] - [0,A-1]
A, B = input().split()
dp_1 = dp_table(20, 2, 2)  # dp[??????][N?????][4,9????]
dp_2 = dp_table(20, 2, 2)
print(solve(dp_1, B) - solve(dp_2, str(int(A) - 1)))