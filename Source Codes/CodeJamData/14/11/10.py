#!/usr/bin/env python3

from collections import defaultdict

def rl(t):
    return [ t(_) for _ in input().split() ]

def ok(n, slots, devs, mask):
    e = [ [ id for id,dev in enumerate(devs) if slot == (dev ^ mask) ] for slot in slots ]

    vis = [ False ] * n
    match = [ -1 ] * n
    count = 0
    
    def go(i):
        for j in e[i]:
            if not vis[j]:
                vis[j] = True
                if match[i] == -1 or go( match[i] ):
                    match[i] = j
                    return True
        return False

    for i in range(n):
        vis = [ False ] * n
        if go(i):
            count += 1

    return count == n

def count_1( v ):
    s = '{0:b}'.format(v)
    c = len( [_ for _ in list(s) if _ == '1' ] )
    return c

def solve(n, slots, devs):
    masks = [ slot ^ dev for slot in slots for dev in devs ]

    mask_counter = defaultdict(int)
    for mask in masks:
        mask_counter[ mask ] += 1

    masks = [ mask for mask in list(set(masks)) if mask_counter[ mask ] >= n ]
    
    masks.sort( key = lambda _ : count_1(_) )
    
    for mask in masks:
        if ok(n, slots, devs, mask):
            return count_1(mask)

    return 'NOT POSSIBLE'

def main():
    T, *_ = rl(int)
    for C in range(1,T+1):
        n, l, *_ = rl(int)
        slots = rl( lambda _: int(_,2) )
        devs = rl( lambda _: int(_,2) )

        answer = solve(n,slots,devs)
        print('Case #%d:'%C, answer)


if __name__ == '__main__':
    main()
