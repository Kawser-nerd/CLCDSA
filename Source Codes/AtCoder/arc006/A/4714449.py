E = list(map(int, input().split()))
B = int(input())
L = list(map(int, input().split()))
num = 0
b = False
for i in range(6):
    if L[i] in E:
        num += 1
    if B in L:
        b = True

if num == 6:
    print('1')
elif num == 5 and b:
    print('2')
elif num == 5:
    print('3')
elif num == 4:
    print('4')
elif num == 3:
    print('5')
else:
    print('0')