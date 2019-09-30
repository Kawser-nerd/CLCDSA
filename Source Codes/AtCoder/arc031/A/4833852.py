name = input()
count = 0

for s in name:
    if s is name[-1-count]:
        count += 1
    else:
        print('NO')
        exit()
print('YES')