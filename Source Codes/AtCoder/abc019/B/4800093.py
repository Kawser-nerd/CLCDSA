s = input()
count = 1
res = []

for i in range(len(s)):
  if i != len(s) - 1 and s[i] == s[i + 1]:
    count += 1
  else:
    res.append(s[i] + str(count))
    count = 1

print(''.join(res))