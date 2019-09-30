# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

s = input()
s = s[:-1]
rev = reversed(s)

for i, j in zip(s, rev):
    if i == j:
        continue
    elif i == "*":
        continue
    elif j == "*":
        continue
    else:
        print("NO")
        exit()
print("YES")