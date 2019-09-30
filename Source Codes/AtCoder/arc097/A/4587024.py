s = input()
k = int(input())

keys = []
for start in range(len(s)):
  for end in range(start+1, min(start+6, len(s)+1)):
    key = s[start:end]
    if key in keys:
      continue
    if len(keys) < 5:
      keys.append(key)
      keys.sort()
    elif keys[-1] > key:
      keys.append(key)
      keys.sort()
      keys = keys[:-1]
print(keys[k-1])