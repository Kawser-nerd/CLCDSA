from sys import stdin
input = stdin.readline

E = list(map(int, input().split()))
b = int(input())
L = list(map(int, input().split()))
cou = 0

for l in L:
    if l in E:
        cou += 1

if cou == 6:
    ans = 1
elif cou == 5 and b in L:
    ans = 2
elif cou == 5:
    ans = 3
elif cou == 4:
    ans = 4
elif cou == 3:
    ans = 5
else:
    ans = 0

print(ans)