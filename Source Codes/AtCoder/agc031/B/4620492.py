#encoding: utf-8

n = int(input())
c = []
for i in range(n):
    c.append(int(input()))

dp = 1
prev = [0] * (max(c) + 1)
x = 0
for i in c:
    if x != i:
        dp += prev[i]
        prev[i] = dp
    x = i

print(dp % (10 ** 9 + 7))