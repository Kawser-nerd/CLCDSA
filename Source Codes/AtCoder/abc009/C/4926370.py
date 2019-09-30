from collections import Counter
 
N, K = map(int, input().split(' '))
S = input()
R = sorted(S)
T = ''
diff = 0
 
for i in range(N):
    counter = Counter(S[:i+1]) - Counter(T)
    #print(counter, Counter(S[:i+1]), Counter(T))
    for r in R:
        diff1 = diff + (r != S[i])
        diff2 = sum(counter.values()) - (counter[r] > 0)
        if diff1 + diff2 <= K:
            T += r
            R.remove(r)
            diff = diff1
            break
print(T)