N,M = map(int,input().split())
s_num = N
cc_num = M // 2
# cc???????????????
if min(s_num,cc_num) == cc_num:
    print(cc_num)
    exit()
# s??????????????cc?s?????????????
scc_num = s_num
cc_remains = cc_num - scc_num
sep_2 = cc_remains // 2
scc_num += sep_2
print(scc_num)