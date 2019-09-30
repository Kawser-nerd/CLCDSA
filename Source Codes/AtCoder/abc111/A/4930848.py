n = input()
change = ''
for i in n:
    if i == '1':
        change += '9'
    else:
        change += '1'
print(change)