# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

s = input()

l = ["i", "c", "t"]
L = ["I", "C", "T"]
f = 0
for c in s:
    if c == l[f] or c == L[f]:
        f += 1
    if f == 3:
        break
if f == 3:
    print("YES")
else:
    print("NO")