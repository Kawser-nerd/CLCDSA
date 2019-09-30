from functools import lru_cache


def get_bit(n, d):
    return (n >> d) & 1


@lru_cache(maxsize=None)
def xor(bit, digit):
    """
    A ??????????? digit ??? bit ? XOR ????
    :param int bit:
    :param int digit:
    :return:
    """
    assert bit in [0, 1]
    # bit <<= digit
    # mask = 1 << digit
    # return sum([(a ^ bit) & mask for a in A])
    if bit == 0:
        return bit_counts[digit] << digit
    else:
        return (N - bit_counts[digit]) << digit


N, K = map(int, input().split())
A = list(map(int, input().split()))

DIGIT = 50
bit_counts = [sum([get_bit(a, d=d) for a in A]) for d in range(DIGIT)]

# [?][k ???????????????]
dp = [[-float('inf') for _ in range(2)] for _ in range(DIGIT + 1)]
# dp = np.empty([DIGIT + 1, 2], dtype=int)
# dp.fill(-np.inf)

dp[-1][0] = 0
for d in reversed(range(DIGIT)):
    k = get_bit(K, d=d)
    # bit=k
    dp[d][0] = max(dp[d][0], dp[d + 1][0] + xor(bit=k, digit=d))
    # k==1 ?? bit=0 ? OK
    if k == 1:
        dp[d][1] = max(dp[d][1], dp[d + 1][0] + xor(bit=0, digit=d))
    # k ???????????????? bit ????????? OK
    dp[d][1] = max(dp[d][1], dp[d + 1][1] + xor(bit=0, digit=d))
    dp[d][1] = max(dp[d][1], dp[d + 1][1] + xor(bit=1, digit=d))

print(max(dp[0]))