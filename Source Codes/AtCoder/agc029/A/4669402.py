s = input()
n = len(s)
count = 0
m = 0
for i in range(n):
    if s[i] == 'W':
        count += i - m
        m += 1
print(count)