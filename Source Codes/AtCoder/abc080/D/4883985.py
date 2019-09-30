from numpy import cumsum
n, c = [int(item) for item in input().split()]
stc = [[int(item) for item in input().split()] for _ in range(n)] 
stc.sort(key=lambda x: (x[2], x[0]))

timeline = [0] * (10**5 + 1)
prev_c = -1 
for s, t, c in stc:
    if prev_c != c:
        prev_t = -100
    if prev_t != s:
        timeline[s-1] += 1
        timeline[t] += -1
    else:
        timeline[s] += 1
        timeline[t] += -1
    prev_t = t
    prev_c = c

print(max(cumsum(timeline)))