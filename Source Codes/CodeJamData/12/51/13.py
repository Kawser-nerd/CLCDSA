import collections
import sys

bak = sys.stdin
sys.stdin = open('input.txt')

for kase in range(int(input())):
    print("Case #{}:".format(kase+1), end="")
    n = int(input())
    l = input()
    p = input().split()
    p = [int(i) for i in p]
    s = [(100-p[i], i) for i in range(len(p))]
    s.sort()
    ans = ""
    for i in s:
        ans += ' ' + str(i[1])
    print(ans)

sys.stdin = bak
input()
