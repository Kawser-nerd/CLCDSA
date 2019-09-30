N, L = map(int, input().split())
S = input()

ans = 0
count = 0
for string in S:
    if string == '+':
        count += 1
    else:
        count -= 1
    if count == L:
        ans += 1
        count = 0

print(ans)