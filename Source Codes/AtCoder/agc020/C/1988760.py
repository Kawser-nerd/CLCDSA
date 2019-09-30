# coding=utf-8

N = int(input())
dp = 1
asum = 0
for a in input().split(" "):
    x = int(a)
    asum += x
    dp = dp|(dp<<x)

for i in range((asum+1)//2, asum+1):
    if (dp>>i)&1:
        print(i)
        break