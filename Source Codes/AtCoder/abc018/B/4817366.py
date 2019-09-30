s = list(input())
n = int(input())
for i in range(n):
    x, y = map(int, input().split())
    a = s[x - 1:y]
    s[x - 1:y] = a[::-1]

for i in s:
    print(i, end='')
print()