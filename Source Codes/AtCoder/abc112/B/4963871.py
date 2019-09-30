N, T = map(int, input().split())
num = 1001

for i in range(N):
    c, t = map(int, input().split())
    if T >= t and num >= c:
        num = c

if num != 1001:
    print(num)
else:
    print('TLE')