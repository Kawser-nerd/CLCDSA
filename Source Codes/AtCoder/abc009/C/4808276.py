from collections import Counter

n,k = map(int,input().split())
S = list(input())

s_sort = sorted(S)
T = ""

miss = 0
counter = Counter(S[:1])
counts = sum(counter.values())

for i in range(n):
    for c in s_sort:
        miss1 = miss + (c != S[i])
        miss2 = counts - (counter[c] > 0)
        if miss1 + miss2 <= k:
            T += c
            s_sort.remove(c)
            miss = miss1
            counter = Counter(S[:i+2])-Counter(T)
            counts = sum(counter.values())
            break
print(T)