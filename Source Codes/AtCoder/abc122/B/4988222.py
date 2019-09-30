S = input()
mojiretsu = ["A","C","G","T"]
s_bin = [int(s in mojiretsu) for s in S]
# print(s_bin)
cnt = 0
cnt_max = 0
for s in s_bin+[0]:
    if s == 0:
        # cnt_max = max(cnt_max, cnt)
        cnt = 0
    if s == 1:
        cnt += 1
        cnt_max = max(cnt_max, cnt)
    
    # print("s:{},cnt:{},cnt_max{}".format(s,cnt,cnt_max))

print(cnt_max)