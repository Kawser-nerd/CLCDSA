import copy
n = int(input())
w = [input() for i in range(n)]
flag = True
count = 0
for i in range(n):
    w_temp = copy.deepcopy(w)
    w_temp.pop(i)
    if w[i] in w_temp:
        print('No')
        exit()
for i in range(1, n):
    if w[i][0] != w[i-1][-1]:
        print('No')
        exit()
print('Yes')