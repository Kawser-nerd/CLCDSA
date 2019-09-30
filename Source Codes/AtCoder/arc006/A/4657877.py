E = [int(_) for _ in input().split()]
B = int(input())
L = [int(_) for _ in input().split()]
cnt = 0

for i in L:
    if i in E:
        cnt += 1

if cnt == 6:
    print(1)
elif cnt < 3:
    print(0)
else:
    if B in L and cnt == 5:
        cnt += 1
    print(8-cnt)