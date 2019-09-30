import sys
sys.setrecursionlimit(10**9)
s1 = "maerd"
s2 = "remaerd"
s3 = "esare"
s4 = "resare"

i = input()
s = ''
for c in reversed(i):
    s += c

l = len(s)

i = 0


def dfs(i):
    if i == l:
        print("YES")
        exit()
    if i+5 <= l and s[i:i+5] == s1:
        dfs(i+5)
    elif i+7 <= l and s[i:i+7] == s2:
        dfs(i+7)
    elif i+5 <= l and s[i:i+5] == s3:
        dfs(i+5)
    elif i+6 <= l and s[i:i+6] == s4:
        dfs(i+6)
    else:
        print("NO")
        exit()


dfs(0)