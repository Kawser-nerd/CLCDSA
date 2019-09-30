# coding: utf-8

n_mou = int(input())
l_mou = list(map(int, input().split()))
l_mou_ind = [[l_mou[i], i] for i in range(n_mou)]
l_mou_ind.sort()

l_ans = [0 for i in range(n_mou)]

l_ans[0] = l_mou_ind[0][0] * n_mou
min_index = l_mou_ind[-1][1]
for i in range(n_mou - 1, 0, -1):
    min_index = min(min_index, l_mou_ind[i][1])
    if l_mou_ind[i - 1][0] != l_mou_ind[i][0]:
        l_ans[min_index] += (l_mou_ind[i][0] - l_mou_ind[i - 1][0]) * (n_mou - i)

for i in range(n_mou):
    print(l_ans[i])