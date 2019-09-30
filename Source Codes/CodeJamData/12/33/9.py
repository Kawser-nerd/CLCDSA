#!/usr/bin/env python


def search(boxes, toys, ta, tb, visited):
    if ta == 0 or tb == 0:
        return 0
    elif ta < 0 or tb < 0:
        return float('-inf')
    if (ta,tb) not in visited:
        sa = 0
        for pa in range(0,len(boxes),2):
            sa += boxes[pa]
            if sa >= ta:
                sa -= boxes[pa]
                break
        sb = 0
        for pb in range(0,len(toys),2):
            sb += toys[pb]
            if sb >= tb:
                sb -= toys[pb]
                break

        na, nb = ta - sa, tb - sb
        if boxes[pa+1] == toys[pb+1]:
            if na <= nb:
                visited[(ta,tb)] = na+search(boxes, toys, ta - na, tb - na, visited)
            else:
                visited[(ta,tb)] = nb+search(boxes, toys, ta - nb, tb - nb, visited)
        else:
            visited[(ta,tb)] = max(search(boxes,toys,sa,tb,visited),
                                   search(boxes,toys,ta,sb,visited))
    return visited[(ta,tb)]

t = int(input())
for case in range(1,t+1):
    n,m = map(int,input().strip().split())
    boxes = list(map(int,input().strip().split()))
    a1 = []
    toys = list(map(int,input().strip().split()))
    a2 = []

    ta = sum([boxes[i] for i in range(0,len(boxes),2)])
    tb = sum([toys[i] for i in range(0,len(toys),2)])
    visited = {}

    print('Case #{}: {}'.format(case, search(boxes,toys,ta,tb,visited)))
