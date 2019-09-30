# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

d = dict()
d['O'] = '0'
d['D'] = '0'
d['I'] = '1'
d['Z'] = '2'
d['S'] = '5'
d['B'] = '8'

s = input()
ans = ''
for c in s[:-1]:
    if ord('0') <= ord(c) <= ord('9'):
        ans += c
    else:
        ans += d[c]
print(ans)