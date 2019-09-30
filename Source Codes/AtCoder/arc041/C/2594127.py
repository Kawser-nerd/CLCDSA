import sys

def bunny(L, R):
    L=L[::-1]
    gap = l - L[0] if not R else R[0] - 1 if not L else R[0] - L[0] - 1
    len_L, len_R = len(L), len(R)
    gap_L = sum(L[0]-L[i]-i for i in range(1,len_L))
    gap_R = sum(R[i]-R[0]-i for i in range(1,len_R))
    return gap_L + gap * max(len_L, len_R) + gap_R

N, l = map(int, input().split())
rabbit, b2b = [[], []], 0
ans = 0
for e in sys.stdin:
    x, d = int(e[:-3]), e[-2]
    if b2b == 0 or d == 'L':
        rabbit[d == 'L'] += [x]
        b2b = d == 'L'
    else:
        ans += bunny(*rabbit)
        rabbit, b2b = [[x], []], 0
ans += bunny(*rabbit)
print(ans)