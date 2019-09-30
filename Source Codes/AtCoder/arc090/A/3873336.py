N = int(input())
A1 = list(map(int, input().split(' ')))
A2 = list(map(int, input().split(' ')))
now_gain = sum(A2) + A1[0]
max_gain = now_gain
for i in range(1, N):
    now_gain = now_gain - A2[i-1] + A1[i]
    max_gain = max(max_gain, now_gain)
print(max_gain)