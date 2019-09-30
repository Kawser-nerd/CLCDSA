s = input()
counter = 0
max_count = 0
for i in range(len(s)):
    if s[i] == 'A' or s[i] == 'C' or s[i] =='G' or s[i] == 'T':
        counter += 1
    else:
        if counter > max_count:
            max_count = counter
            counter = 0
        else:
            counter = 0
if counter > max_count:
    max_count = counter
print(max_count)