""" AtCoder """

N = int(input())
a = list(map(int, input().split()))

right = 1
left = 0
ans = 0

def f(n):
    a = 0
    for i in range(n, 0, -1):
        a += i
    return a

if N == 1:
    print(1)

while right < N:
    n = 0
    while a[right - 1] < a[right]:
        n += 1
        right += 1
        if right >= N:
            break
    ans += f(n)
    right += 1

print(ans + N)