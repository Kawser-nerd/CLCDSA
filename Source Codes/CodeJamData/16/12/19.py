#!/usr/bin/python3
import sys

if __name__ == '__main__':
    t = int(sys.stdin.readline())
    for case_num in range(1, t+1):
        n = int(sys.stdin.readline())
        cnt = dict()
        for i in range(2*n-1):
            nums = [int(x) for x in sys.stdin.readline().split()]
            for x in nums:
                cnt[x] = cnt.get(x, 0) + 1
        sol = sorted([k for k, v in cnt.items() if v % 2 == 1])
        assert len(sol) == n
        print('Case #{0}: {1}'.format(case_num, ' '.join(str(x) for x in sol)))
