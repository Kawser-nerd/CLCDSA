# encoding: utf-8
N, D, K = map(int, input().split())
LR = [list(map(int, input().split())) for i in range(D)]
ST = [list(map(int, input().split())) for i in range(K)]

ST_tmp = list(enumerate(ST))
anss = [0] * K
for Li, Ri in LR:
    # print("#", Li, Ri)
    ST_next = []
    for j, (Sj, Tj) in ST_tmp:
        # print("##", j, Sj, Tj)
        anss[j] += 1
        if Sj < Tj:
            if Li <= Sj <= Ri: S_next = min((Tj, Ri))
            else: S_next = Sj
        elif Sj > Tj:
            if Li <= Sj <= Ri: S_next = max((Tj, Li))
            else: S_next = Sj
        if S_next != Tj: ST_next.append((j, (S_next, Tj)))
    ST_tmp = list(ST_next)
    if len(ST_tmp) < 1: break
    
for ans in anss: print(ans)