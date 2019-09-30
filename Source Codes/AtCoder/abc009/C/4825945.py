from collections import Counter

n, k = map(int, input().split())
S = list(input())
S_sort= sorted(S)

T =""
count = 0
for i in range(n):
    for j, s in enumerate(S_sort):
        counter = Counter(S[len(T)+1:])
        counter_sort = Counter(S_sort)
        counter_sort[s] -= 1
        dif = 0 + (S[len(T)] != s)

        for c in counter.keys():
            if counter[c] - counter_sort[c] > 0:
                dif += counter[c] - counter_sort[c]
        if dif + count <= k:
            if S[len(T)] != s:
                count += 1
            T += s
            S_sort.remove(s)
            break

print(T)