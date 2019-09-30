s_long = input()

count = 0
prev = ''

for s in s_long:
    if prev == '':
        prev = s
        continue

    if prev != s:
        count += 1
        prev = s

print(count)