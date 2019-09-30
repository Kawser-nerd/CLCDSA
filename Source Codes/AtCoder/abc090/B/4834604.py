A, B = map(int, input().split())
count = 0
for n in range(A, B + 1):
    if n == int(str(n)[::-1]):
        count += 1
print(count)