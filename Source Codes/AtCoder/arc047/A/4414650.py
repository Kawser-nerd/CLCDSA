# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N, L = map(int, input().split())
s = input()
clash = 0
tab = 1
for c in s:
    if c == "+":
        tab += 1
        if tab > L:
            clash += 1
            tab = 1
    else:
        tab -= 1
print(clash)