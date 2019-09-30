from copy import deepcopy
from itertools import chain


N, M, Y, Z = map(int, input().split())
color_dict = {}
color_pts = [0]*(M+1)
for i, (c, p) in enumerate((input().split() for _ in [0]*M), start=1):
    color_dict[c] = i
    color_pts[i] = int(p)

blocks = [color_dict[c] for c in input()]

union_bitsets = [[]] + [[2**i | j for j in range(2**M)] for i in range(M)]
combo_bonus = [[]] + [[Y if i == j else 0 for j in range(M+1)] for i in range(1, M+1)]

next_dp = [[float("-inf")]*(M+1) for _ in [0]*(2**M)]
next_dp[0][0] = 0

for color in blocks:
    point = color_pts[color]
    color_bit = 2**(color-1)
    current_dp = deepcopy(next_dp)
    cbonus = combo_bonus[color]

    for bitset, union_bitset in zip(range(2**M), union_bitsets[color]):
        for cv, bonus in zip(current_dp[bitset], cbonus):
            if next_dp[union_bitset][color] < cv+point+bonus:
                next_dp[union_bitset][color] = cv+point+bonus

print(max(max(chain.from_iterable(next_dp[:-1])), max(next_dp[-1])+Z))