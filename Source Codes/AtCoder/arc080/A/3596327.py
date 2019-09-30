N = int(input())
a = list(map(int, input().split()))
odd = 0
even = 0
four = 0
for i in a:
    if i % 4 == 0:
        four += 1
    elif i % 2 == 0:
        even += 1
    else:
        odd += 1
if even == 0:
    if four >= odd - 1:
        print('Yes')
    else:
        print('No')
else:
    if four >= odd:
        print('Yes')
    else:
        print('No')