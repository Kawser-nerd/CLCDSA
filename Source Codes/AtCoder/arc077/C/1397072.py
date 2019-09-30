# E
n, m = map(int, input().split())
a_list = list(map(int, input().split()))


# bonus map
bonus_str_cnt = [0]*(m+1)
bonus_end_vol = [0]*(m+1)
bonus_end_cnt = [0]*(m+1)

# 1
one_res = 0
bonus_cnt = 0
for i in range(n-1):
    difm = (a_list[i+1] - a_list[i]) % m
    if difm > 1:
        if a_list[i] + 2 > m:
            bonus_str_cnt[(a_list[i] + 2) - m] += 1
        else:
            bonus_str_cnt[a_list[i] + 2] += 1
        bonus_end_cnt[a_list[i+1]] += 1
        bonus_end_vol[a_list[i+1]] += difm - 1
    if difm <= a_list[i+1]:
        one_res += difm
    else:
        one_res += a_list[i+1]
        bonus_cnt += 1

res_list = [one_res]
res = one_res
for i in range(2, m+1):
    res += bonus_end_vol[i-1]
    bonus_cnt += bonus_str_cnt[i] - bonus_end_cnt[i-1]
    res -= bonus_cnt
    res_list.append(res)

print(min(res_list))