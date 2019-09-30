w = input()
set_w = set(w) # ??????
for i in set_w:
    if (w.count(i) % 2 != 0):
        print('No')
        exit()
print('Yes')