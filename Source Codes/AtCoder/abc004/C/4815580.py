N = int(input())
a = N%30
ls = ['1','2','3','4','5','6']
for i in range(a):
    b = i%5
    ls[b], ls[b+1] = ls[b+1], ls[b]
print(''.join(ls))