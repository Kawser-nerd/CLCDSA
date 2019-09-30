def b_perfect_number(N):
    def divisor_list(n):
        # n ?????????
        ret = []
        for k in range(1, int(n**0.5) + 1):
            if n % k == 0:
                ret.append(k)
                if k != n // k:
                    ret.append(n // k)
        ret.sort()
        return ret

    # ?????????????????2????????
    div_list = divisor_list(N)
    div_sum = sum(div_list)
    if div_sum == 2 * N:
        ans = 'Perfect'
    elif div_sum < 2 * N:
        ans = 'Deficient'
    else:
        ans = 'Abundant'
    return ans

N = int(input())
print(b_perfect_number(N))