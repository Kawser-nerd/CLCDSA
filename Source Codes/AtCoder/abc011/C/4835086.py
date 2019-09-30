import sys

N = int(input())
NG1 = int(input())
NG2 = int(input())
NG3 = int(input())

if N == NG1 or N == NG2 or N == NG3:
    print('NO')
    sys.exit()

queue = []
queue.append((0, N))
judge = []

while queue:
    a = queue.pop(0)
    for i in range(3):
        b = a[1] - [1, 2, 3][i]
        if b != NG1 and b != NG2 and b != NG3 and a[0] < 100:
            num = (a[0]+1, b)
            if b > 0 and num[0] < 100 and num not in judge and (100-num[0])*3 >= b:
                queue.append(num)
                judge.append(num)
            elif b == 0:
                print('YES')
                sys.exit()
            else:
                pass

print('NO')