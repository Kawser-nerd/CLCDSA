s = int(input())
progression = [s]
n = s
count = 1
while True:
    count += 1
    if n % 2 == 0:
        n = n/2
    else:
        n = 3 * n + 1

    if n in progression:
        break
    else:
        progression.append(n)

print(count)