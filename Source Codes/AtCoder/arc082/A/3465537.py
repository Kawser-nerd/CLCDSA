N = int(input())
A = list(map(int, input().split()))

count = [0 for _ in range(10 ** 5 + 1)]
for a in A:
    count[a] += 1

ret = 0

for i in range(1, 10 ** 5):
    ret = max(ret, count[i - 1] + count[i] + count[i + 1])

print(ret)