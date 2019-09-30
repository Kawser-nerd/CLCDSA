import sys

N, K = map(int,input().split())
D = list(input().split())
for i in range(N, 100001):
    flg = 1
    cost = str(i)
    digit = len(cost)
    for j in range(digit):
        if cost[j] in D:
            flg = 0
            break
    if flg == 1:
        print(cost)
        sys.exit()
print("error")