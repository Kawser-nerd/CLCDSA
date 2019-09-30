# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

s = input()
s = s[:-1]
s_rev = reversed(s)

for i, j in zip(s, s_rev):
    if i == j:
        continue
    else:
        print("NO")
        exit()
print("YES")