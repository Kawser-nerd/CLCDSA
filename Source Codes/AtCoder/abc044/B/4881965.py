w = input()
r = 'Yes'
for c in w:
    if w.count(c) % 2 != 0:
        r = 'No'
        break
print(r)