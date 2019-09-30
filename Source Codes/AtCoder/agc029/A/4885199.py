txt = input()
txt_list = list(txt)

count = 0
n_b = 0
n_w = 0
i = 0
for i in range(len(txt_list)):
    if txt_list[i] == 'W':
        n_w += 1
    if (i>=1 and txt_list[i-1] == 'W' and txt_list[i] == 'B') or (i==len(txt_list)-1 and txt_list[i] == 'W'):
        count += n_b * n_w
        n_w = 0
    if txt_list[i] == 'B':
        n_b += 1

print(count)