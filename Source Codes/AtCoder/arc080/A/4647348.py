from math import ceil
N = int(input())
A = list(map(int, input().split()))
num2 = 0
num4 = 0
numO = 0
for num in A:
    if num % 4 == 0:
        num4 += 1
        continue
    elif num % 2 == 0:
        num2 += 1
        continue
    else:
        numO += 1
if num2 > 0:
    if numO > num4:
        print('No')
    else:
        print('Yes')
else:
    if numO > ceil((num4 + numO) / 2):
        print('No')
    else:
        print('Yes')