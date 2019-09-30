N, D, K = map(int, input().split())
LR = [tuple(int(x) for x in input().split()) for _ in range(D)]
ST = [list(map(int, input().split())) for _ in range(K)]

KL = [st[0] for st in ST]
KR = [st[0] for st in ST]
KD = [D for _ in range(K)]

for i, lr in enumerate(LR):
    day = i+1
    l, r = lr

    for k in range(K):
        if KD[k]==D and KL[k]<=r and l<=KR[k]:
            KL[k] = min(KL[k], l)
            KR[k] = max(KR[k], r)
            if KD[k]==D and KL[k]<=ST[k][1]<=KR[k]:
                KD[k]=day

for d in KD:
    print(d)