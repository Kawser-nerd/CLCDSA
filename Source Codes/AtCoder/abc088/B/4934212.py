n = int(input())
a = sorted(list(map(int, input().split())), reverse=True)

result = 0
is_even = True
for x in a:
    result += x if is_even else -x
    is_even = not is_even
print(result)