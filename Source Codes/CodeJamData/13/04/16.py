#!/usr/bin/python

from collections import Counter

def get():
    k, n = map(int, raw_input().strip().split())
    keys = Counter(map(int, raw_input().strip().split()))
    connects = []
    for x in xrange(n):
        connects.append(map(int, raw_input().strip().split()))
    save = [None] * (1<<n)
    
    def dfs(now, m):
        # check if we can open it
        t = connects[now][0]
        if keys[t] <= 0:
            return False

        # check memo
        m |= 1 << now
        if save[m] is not None:
            return save[m]

        # deal with this level
        order.append(now + 1)
        keys[t] -= 1
        visited[now] = True
        for x in connects[now][2:]:
            keys[x] += 1

        # check end
        if all(visited):
            save[m] = True
            return True

        # sub
        for x in xrange(n):
            if not visited[x] and dfs(x, m):
                save[m] = True
                return True

        # reset
        keys[t] += 1
        visited[now] = False
        order.pop()
        for x in connects[now][2:]:
            keys[x] -= 1

        save[m] = False
        return False

    for x in xrange(n):
        visited = [False] * n
        order = []
        if dfs(x, 0):
            return ' '.join(map(str, order))

    return 'IMPOSSIBLE'

n = input()
for x in xrange(n):
    print 'Case #%d: %s' % (x+1, get())
