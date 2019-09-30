s = list(input())

p = s.count('+')
m = s.count('-')

a = []

for i in range(len(s)):
    if s[i] == 'M':
        a.append(p - m)
    elif s[i] == '+':
        p -= 1
    else:
        m -= 1

a.sort()

print(sum(a[len(a) // 2:]) - sum(a[:len(a) // 2]))