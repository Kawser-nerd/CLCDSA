#!/usr/bin/python3

def run():
    n, l = tuple(int(x) for x in input().split())
    G = input().split()
    B = input().strip()
    if B in G:
        return "IMPOSSIBLE"
    if l == 1:
        p1 = "?"
        p2 = "0"
    else:
        p1 = "?" * (l-1)
        p2 = "10?" + "10" * l
    return "%s %s" % (p1, p2)


tc = int(input())
for i in range(tc):
    res = run()
    print("Case #%d: %s" % (i+1, res))
