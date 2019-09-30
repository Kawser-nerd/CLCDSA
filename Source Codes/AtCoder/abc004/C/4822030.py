N = int(input())

N_substance = N%30

lst = ['1','2','3','4','5','6']
for i in range(N_substance):
    tmp = lst[i%5]
    lst[i%5] = lst[i%5+1]
    lst[i%5+1] = tmp

print(''.join(lst))