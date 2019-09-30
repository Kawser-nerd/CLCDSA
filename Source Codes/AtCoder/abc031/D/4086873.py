from itertools import product
K, N = map(int, input().split())
Codes, Words = [], []
for i in range(N):
    v, w = input().split()
    Codes.append(list(map(lambda x: int(x) - 1, list(v))))
    Words.append(w)


for ptn in product(range(1, 4), repeat=K):
    ans = [''] * K
    for code, word in zip(Codes, Words):
        if len(word) != sum([ptn[i] for i in code]):
            break
    else:
        for code, word in zip(Codes, Words):
            cnt = 0
            for c in code:
                ans[c] = word[cnt: cnt + ptn[c]]
                cnt += ptn[c]
        print(*ans, sep='\n')
        exit()