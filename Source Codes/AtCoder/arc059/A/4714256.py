N = int(input())
a = [int(_) for _ in input().split()]
ans = float ('inf')

for i in range(-100, 101):
    tmp = 0
    for j in a:
        tmp += (i - j)**2
    if tmp < ans:
        ans = tmp

print(ans)