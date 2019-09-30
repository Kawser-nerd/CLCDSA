S = input()

numbers = list(map(str, range(0, 10)))
ans = ''
for string in S:
    if string in numbers:
        ans += string

print(ans)