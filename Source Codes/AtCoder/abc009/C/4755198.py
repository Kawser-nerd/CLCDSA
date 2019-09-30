from collections import Counter
n, k = map(int, input().split())
s = input()
counters = {i+1:Counter(s[:i+1]) for i in range(n)}
     
def possible(solution):
    diff1 = sum(a != b for a, b in zip(solution, s))
    if diff1 > k: return False
    diff2 = sum((counters[len(solution)] - Counter(solution)).values())
    return diff1 + diff2 <= k
     
solution = []
remaining = sorted(s)
for _ in range(n):
    for j, c in enumerate(remaining):
        if c is None: continue
        solution.append(c)
        if possible(solution):
            remaining[j] = None
            break
        solution.pop()
print(''.join(solution))