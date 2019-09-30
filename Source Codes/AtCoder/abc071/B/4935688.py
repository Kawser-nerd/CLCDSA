s = sorted(input())
result = ''

for i in range(97, 97+26):
    c = chr(i)
    if c not in s:
        result = c
        break

print(result if result != '' else 'None')