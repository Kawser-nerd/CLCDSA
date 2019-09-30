import sys
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())

s = ns()
for i in range(26):
    if chr(i + ord('a')) not in s:
        print(chr(i + ord('a')))
        exit()
print('None')