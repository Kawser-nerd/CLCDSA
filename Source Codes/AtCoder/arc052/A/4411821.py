import re
# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

s = input()
pat = r'(\d)+'
res = re.search(pat, s)
if res:
    print(res.group())
else:
    print("err")