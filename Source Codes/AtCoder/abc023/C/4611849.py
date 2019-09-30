import sys
import collections
import itertools


def parse_input(input_lines):
    return tuple(map(lambda sl: tuple(map(int, sl)),
                     map(lambda s: s.strip().split(),
                         input_lines)))


def main(R, C, K, set_candies):
    r_candies = [0] * R
    c_candies = [0] * C
    for i, (r, c) in enumerate(set_candies):
        r_candies[r - 1] += 1
        c_candies[c - 1] += 1
    r_sums = collections.Counter(r_candies)
    c_sums = collections.Counter(c_candies)

    count = 0
    for i in range(K + 1):
        count += r_sums[i] * c_sums[K - i]

    for r, c in set_candies:
        got_candies = r_candies[r - 1] + c_candies[c - 1]
        if got_candies == K:
            count -= 1

        if got_candies == K + 1:
            count += 1

    return count


if __name__ == '__main__':
    (R, C, K), _, *set_candies = parse_input(sys.stdin.readlines())
    print(main(R, C, K, set_candies))