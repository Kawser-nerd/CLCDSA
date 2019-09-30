import copy

N = int(input())
list_c = []
for i in range(N):
    list_c.append(int(input()))

sum_e_v = 0
for coin in list_c:
    tmp = copy.deepcopy(list_c)
    tmp.remove(coin)
    ct = 0
    for x in tmp:
        if coin % x == 0:
            ct += 1.0
    if ct % 2 == 1:
        sum_e_v += 0.5
    else:
        sum_e_v += (ct + 2.0)/(2.0*ct + 2)

print(sum_e_v)