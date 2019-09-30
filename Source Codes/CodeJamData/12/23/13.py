from itertools import combinations
from random import randint
from collections import defaultdict
from time import time

def solve(numbers):

    nnum = len(numbers)
    sums = defaultdict(list)
    t0 = time()
    for i in range(2, nnum):
        for subset in combinations(numbers, i):
            if time()  - t0 > 30: return None
            s = set(subset)
            s_sum = sum(s)
            for other in sums[s_sum]:
                if len(s & other) == 0:
                    return s, other
            sums[s_sum].append(s)
    return None

def test():
    nums = set()
    while len(nums) < 500:
        draw = 500 - len(nums)
        [nums.add(randint(1, 10**12)) for i in range(draw)]

    result = solve(nums)
    print result
    print sum(result[0]), sum(result[1])


def main():
    import sys

    data = file(sys.argv[1]+'.in').readlines()
    with open(sys.argv[1]+'.out','w') as out:
        for i, line in enumerate(data[1:]):
            nums = map(int, line.strip().split())
            answer = solve(nums[1:])
            if answer is not None:
                a1 = ' '.join(map(str, answer[0]))
                a2 = ' '.join(map(str, answer[1]))
                response = "Case #%i:\n%s\n%s\n" % (i+1, a1, a2)
            else:
                response= "Case #%i:\nImpossible\n" % (i+1)
            print response
            out.write(response)


if __name__ == "__main__":
    main()
    #test()