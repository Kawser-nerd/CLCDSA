from itertools import product
H,W,K = list(map(int, input().split()))
mod=int(1e9+7)

memo = [[0]*W for _ in range(H+1)]
memo[0][0]=1
#memo[h][w] = h???w??????

from itertools import product
def one_row(W):
    one_row_amida={i:{i:0 for i in range(W)} for i in range(W)}

    for p in product([0,1], repeat=W-1):
        if any([p[i]==1 and p[i+1]==1 for i in range(W-2)]):
            continue
        after = [i for i in range(W)]
        for i in range(W-1):
            if p[i]:
                after[i], after[i+1] = after[i+1], after[i]
        for i, a in enumerate(after):
            one_row_amida[i][a] += 1
    return one_row_amida

one_row_amida = one_row(W)

for h in range(H):
    for w in range(W):
        for j in range(W):
            memo[h+1][j] += memo[h][w] * one_row_amida[w][j]
    memo[h+1] = [x%mod for x in memo[h+1]]

answer = memo[H][K-1]

print(answer)