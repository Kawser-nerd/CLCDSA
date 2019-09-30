# coding:utf-8

import sys
from collections import deque

INF = float('inf')
MOD = 10 ** 9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def S(): return input()


n, l = LI()
# L: 0, R: 1
rabbit = [(int(x), 0 if d == 'L' else 1) for x, d in (LS() for _ in range(n))]
rabbit = rabbit + [(l + 1, 1), (l + 2, 0), (l + 3, 1)]

state = 0
left = 1
rabbit_l = deque()
rabbit_r = deque()
ans = 0
for i in range(n + 3):
    x, d = rabbit[i]

    if state == 0:
        if d == 0:
            ans += x - left
            left += 1

        else:
            rabbit_r.append(x)
            state = 1

    elif state == 1:
        if d == 1:
            rabbit_r.append(x)

        else:
            rabbit_l.append(x)
            state = 2

    else:
        if d == 0:
            rabbit_l.append(x)

        else:
            num_of_rabbit_r = len(rabbit_r)
            num_of_rabbit_l = len(rabbit_l)
            breadth = rabbit_l[0] - rabbit_r[-1] - 1
            jump_r = [0]
            for k in range(1, num_of_rabbit_r)[::-1]:
                jump_r.append(jump_r[-1] + abs(rabbit_r[k] - rabbit_r[k - 1]) - 1)
            jump_l = [0]
            for k in range(1, num_of_rabbit_l):
                jump_l.append(jump_l[-1] + abs(rabbit_l[k] - rabbit_l[k - 1]) - 1)

            if num_of_rabbit_r >= num_of_rabbit_l:
                ans += breadth * num_of_rabbit_r
            else:
                ans += breadth * num_of_rabbit_l
            # print(rabbit_r, rabbit_l, jump_r, jump_l, breadth)

            ans += sum(jump_r) + sum(jump_l)

            rabbit_l = deque()
            rabbit_r = deque()

            rabbit_r.append(x)

            state = 1
    # print(state, ans, rabbit_l, rabbit_r)

print(ans)