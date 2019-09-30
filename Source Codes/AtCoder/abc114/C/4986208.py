import itertools

n = int(input())
num = ['3','5','7']
elements = []
for i in range(1,len(str(n))+1):
    options = itertools.product(num, repeat=i)
    for s in options:
        num1 = ''.join(s)
        elements.append(num1)

cnt = 0

for i in range(len(elements)):
    if int(elements[i]) <= n:
        if '3' in elements[i] and '5' in elements[i] and '7' in elements[i]:
            cnt += 1
    else:
        break

print(cnt)