w = input()
dct_str = dict.fromkeys(w, 0)
 
for alp in w:
    dct_str[alp] += 1
flag = True
for alp in dct_str.keys():
    if dct_str[alp] % 2 != 0:
        flag = False
 
if flag == True:
    print("Yes")
else:
    print("No")