#!/usr/bin/python3
from pprint import pprint

MAXN = 14;

tests = int(input())
src = {}
chars = ('R', 'P', 'S')
nxt = {'R':'S', 'S':'P', 'P':'R'}
for ch in chars:
    src[(ch, 1)] = ch
for i in range(2, MAXN + 1):
    for ch in chars:
        s1 = src[(ch, i-1)]
        s2 = src[(nxt[ch], i-1)]
        s = ''
        if s1<s2:
            s = s1 + s2
        else:
            s = s2+s1
        src[(ch, i)] = s
#pprint(src)
count = {}
for i in range(1, MAXN + 1):
    for ch in chars:
        s = src[(ch, i)]
        count[(ch, i)] = tuple(s.count(x) for x in chars)
        
#pprint(count)
for test in range(tests):
    n, r, p, s, = map(int, input().split())
    n += 1
    ans = 'Z'
    for ch in chars:
        if count[(ch, n)] == (r, p, s):
            if src[(ch, n)] < ans:
                ans = src[(ch, n)]
    if ans == 'Z':
        ans = 'IMPOSSIBLE'
    print("Case #%d: %s" % (test+1, ans))
    