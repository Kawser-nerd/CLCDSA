#!/usr/bin/env python3


def solve(n, l, lst):

    ans = 0
    np = 1
    while len(lst):
        x, d = lst[0]
        if d == 0:
            ans += x - np
            np += 1
            lst.pop(0)
        else:
            break
    np = l
    while len(lst):
        x, d = lst[-1]
        if d == 1:
            ans += np - x
            np -= 1
            lst.pop()
        else:
            break
    while len(lst):
        rlist = []
        llist = []
        while len(lst):
            x, d = lst[0]
            if d == 1:
                rlist.append(x)
                lst.pop(0)
            else:
                break
        while len(lst):
            x, d = lst[0]
            if d == 0:
                llist.append(x)
                lst.pop(0)
            else:
                break
        rc = len(rlist)
        rx = rlist[-1]
        lc = len(llist)
        lx = llist[0]
        for i, x in enumerate(rlist):
            ans += rx - x - i
        for i, x in enumerate(llist):
            ans += x - lx - i
        ans += (lx - rx - 1) * max(rc, lc)


    return ans


def main():
    n, l = input().split()
    n = int(n)
    l = int(l)
    lst = []
    for _ in range(n):
        x, d = input().split()
        x = int(x)
        lst.append((x, 0 if d == 'L' else 1))


    print(solve(n, l, lst))


if __name__ == '__main__':
    main()