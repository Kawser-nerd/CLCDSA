sp = input()
t = input()
len_t = len(t)
len_s = len(sp)
cand = []
part_start = -1

for i in range(len_s - len_t + 1):
    num = 0
    for j in range(len_t):
        if (sp[i + j] == '?' or sp[i + j] == t[j]):
            num += 1
    
    if (num == len_t):
        part_start = i

if part_start != -1:
    # ???????????????????a??????????????????????????????????????
    ans = sp[:part_start] + t + sp[part_start + len_t:]
    ans = ans.replace('?', 'a')
    print(ans)
else:
    print('UNRESTORABLE')