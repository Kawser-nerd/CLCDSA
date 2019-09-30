import string

s = set(input())
for w in string.ascii_lowercase:
    if w not in s:
        print(w)
        break
else:
    print('None')