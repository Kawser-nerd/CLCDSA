N = int(input())
a = [int(i) for i in input().split()]
if sum(a) % N != 0:
    print(-1)
else:
    x = sum(a) // N #1??????
    left_sum = 0
    bridge = 0
    for i in range(N-1):
        left_sum += a[i] #???
        right_sum = sum(a) - left_sum #???
        if left_sum != x * (i+1) or right_sum != x * (N-i-1):
            bridge += 1
    print(bridge)