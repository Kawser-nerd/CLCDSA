h,w,k = map(int, input().split())
# (???, ????)????
memo = [[0]*w for i in range(h+1)]
for i in range(0, w):
    memo[0][i] = 0
memo[0][0] = 1

# print(memo)

for i in range(1, h+1):
    for j in range(0, 1 << (w-1)):
        skip = False
        for l in range(w-2):
            skip = skip or ((j >> l) & 1 and (j >> (l+1)) & 1)
        # print(skip)
        if not skip:
            for l in range(w):
                if l-1 >= 0 and (j >> (l-1)) & 1:
                    memo[i][l] += memo[i-1][l-1]
                elif l+1 < w and (j >> l) & 1:
                    memo[i][l] += memo[i-1][l+1]
                else:
                    memo[i][l] += memo[i-1][l]
                memo[i][l] = memo[i][l] % 1000000007

# print(memo)
print(memo[h][k-1])