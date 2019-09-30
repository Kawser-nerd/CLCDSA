s = list(input())

a = 0
b = 0
n = len(s)

for i in range(1, n):
    if s[i] == s[i-1]:
        a = i
        break

for i in range(a+1, n):
    if s[i] == s[i-1]:
        b = i
        break

ans_a = ['', 'Mi', '', 'Re', '', 'Do']
ans_b = ['', 'Si', '', 'La', '', 'So', '', 'Fa']

if b - a == 7:
    print(ans_a[a])
else:
    print(ans_b[a])