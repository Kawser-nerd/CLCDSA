w_dic = {}
for _ in range(int(input())):
    s = input()
    w_dic[s[::-1]] = s
#print(w_dic)
for c in sorted(w_dic.keys()):
    print(w_dic[c])