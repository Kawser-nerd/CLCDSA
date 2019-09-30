s = input()
c = 0
for i in 'abc':
  if s.count(i) == 1:
    c += 1
print('Yes' if c == 3 else 'No')