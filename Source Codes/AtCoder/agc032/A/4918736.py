import sys

n = int(input())
b = list(map(int, input().split()))

check = 0
for i in range(n):
    if b[i] > i + 1:
        check = 1

if check == 1:
    print(-1)
    sys.exit()

ans = [] #Wanted Sequence

for i in range(n):
    ans.insert(i + 1 - b[i], b[i])

ans.reverse()

for i in range(n):
    print(ans[i])