import sys
from itertools import accumulate
from collections import deque

def solve():
    N, K = map(int, input().split())
    S = input()

    '''
    if N == 1:
        if K % 2 == 0:
            print(S)
        else:
            print('A' if S == 'B' else 'B')

        return
    '''

    q = deque([1 if c == 'A' else 0 for c in S])
    cb = 0

    for i in range(min(K, 2 * N + K % 2)):
        if q[0] == (cb ^ 1):
            q[0] ^= 1
        else:
            q.popleft()
            q.append(cb)
            cb ^= 1

    # print(q)

    ans = ['A' if (c ^ cb) else 'B' for c in q]
    print(''.join(ans))


def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

if __name__ == '__main__':
    solve()