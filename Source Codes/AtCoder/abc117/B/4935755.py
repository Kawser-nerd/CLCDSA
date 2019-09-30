n = int(input())
l = list(map(int, input().split()))

flag = True
for i in range(n):
    if sum(l) - l[i] > l[i]:
        pass
    else:
        flag = False

if flag:
    print('Yes')
else:
    print('No')