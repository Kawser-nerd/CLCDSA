from collections import Counter
S = input()
A = Counter(list(S)).most_common()

ans = float('inf')
for a in A:
    posi = -1
    interval = 0
    for i in range(len(S)):
        if S[i] == a[0]:
            interval = max(interval, i - posi - 1)
            posi = i
        if i == len(S) - 1:
            interval = max(interval, i - posi)
            posi = i
    #print(a[0], interval)
    ans = min(ans, interval)
        
print(ans)