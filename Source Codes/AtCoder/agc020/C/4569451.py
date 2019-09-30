N = int(input())
a = tuple(map(int, input().split()))
dp = 1
half = (sum(a)+1)//2

for n in a:
    dp |= dp << n

dp >>= half
for i in range(1000000000):
    if dp & 1:
        print(half+i)
        break
    dp >>= 1