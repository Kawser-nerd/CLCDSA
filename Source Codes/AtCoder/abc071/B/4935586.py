s = sorted(input())
# lowercase ? ascii (a-z) ?????
dct = {chr(i):0 for i in range(97, 97+26)}
result = ''

for c in s:
    if c in dct:
        dct[c] += 1

for i in range(97, 97+26):
    c = chr(i)
    if c in dct and dct.get(c) == 0:
        result = c
        break

print(result if result != '' else 'None')