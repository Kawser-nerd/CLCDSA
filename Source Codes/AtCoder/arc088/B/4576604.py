import sys
sys.setrecursionlimit(10**9)

s = input()

K = float('inf')
if all(c == '0' for c in s):
    K = len(s)
elif all(c == '1' for c in s):
    K = len(s)
else:
    for k in range(1, len(s)):
        if s[k] != s[k-1]:
            K = min(K, max(k, len(s)-k))
        else:
            continue

print(K)