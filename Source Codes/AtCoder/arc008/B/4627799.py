n, m = map(int, input().split())
N = list(input())
K = list(input())
dic_N = {}
for i in N:
    if i not in dic_N:
        dic_N[i] = 1
    else:
        dic_N[i] += 1
dic_K = {}
for i in K:
    if i not in dic_K:
        dic_K[i] = 1
    else:
        dic_K[i] += 1

cou = 0
for i in dic_N:
    ni = dic_N[i]
    if i not in dic_K:
        cou = -1
        break
    ki = dic_K[i]
    re = ni//ki
    if ni % ki != 0:
        re += 1
    cou = max(cou, re)

print(cou)