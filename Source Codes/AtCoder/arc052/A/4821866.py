S = input()
num = ''
ls = list(range(0, 10))
for i in range(10):
    ls[i] = str(ls[i])
for x in S:
    if x in ls:
        num += x
print(num)