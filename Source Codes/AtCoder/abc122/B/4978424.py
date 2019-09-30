S = str(input())
counter = 0
max = 0

for i in S:
    if i == 'A' or i == 'T' or i == 'C' or i == 'G':
        counter += 1
        if counter >= max:
            max = counter
    else:
        counter = 0

print(max)