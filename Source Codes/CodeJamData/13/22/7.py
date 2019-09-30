

N_MAX = 1000004

p_n_2n = [1.0]
p_n_2n_1 = [1.0] # probability of n out of 2n - 1

for i in xrange(1, N_MAX):
    last = p_n_2n[-1]
    last *= (2 * i - 1) / float(2 * i)
    p_n_2n.append(last)

for i in xrange(1, N_MAX):
    last = p_n_2n_1[-1]
    last *= (2 * i - 1) / float(2 * i)
    p_n_2n_1.append(last)


# probability of <= x heads in n flips if n is even
def compute_cdf_even(n, x):
    assert x >= 0 and x <= n

    k = n / 2
    if x < k:
        return 1.0 - compute_cdf_even(n, n - x - 1)

    p = p_n_2n[k]
    ret = 0.5 + p / 2
    while k < x:
        p *= (n - k) / float(k + 1)
        ret += p
        k += 1
    return ret

def compute_cdf_odd(n, x):
    assert x >= 0 and x <= n

    k = n / 2 + 1
    p = p_n_2n_1[k]

    if x == k - 1:
        return 0.5
    if x < k:
        return 1.0 - compute_cdf_odd(n, n - x - 1)

    ret = 0.5 + p
    while k < x:
        p *= (n - k) / float(k + 1)
        ret += p
        k += 1
    return ret


def compute_cdf(n, x):
    assert x >= 0
    if x >= n:
        return 1.0

    if (n % 2 == 0):
        return compute_cdf_even(n, x)
    return compute_cdf_odd(n, x)


# q = 8
# prev = 0.0
# for i in xrange(q + 1):
#     r = compute_cdf(q, i)
#     print (r - prev) * (2 ** q)
#     prev = r
# exit()

def num_diamonds(num_layers):
    if num_layers <= 0:
        return 0

    x = 2 * num_layers - 1
    return (x * (x + 1)) / 2


def solve_case(t):
    N, X, Y = [int(x) for x in raw_input().strip().split()]

    if X < 0:
        X = -X

    num_layers = ((X + Y) / 2) + 1
    num_in_layer = 4 * num_layers - 3

    assert num_in_layer + num_diamonds(num_layers - 1) == num_diamonds(num_layers)

    if N <= num_diamonds(num_layers - 1):
        return 0.0
    if N >= num_diamonds(num_layers):
        return 1.0
    if X == 0:
        # need a full layer here
        return 0.0

    remaining = N - num_diamonds(num_layers - 1)
    needed = Y + 1

    if remaining >= needed + num_in_layer / 2:
        return 1.0

    # print remaining, needed

    return 1.0 - compute_cdf(remaining, needed - 1)


T = int(raw_input())
for i in xrange(T):
    answer = solve_case(i + 1)
    print 'Case #%d: %.10f' % (i + 1, answer)
