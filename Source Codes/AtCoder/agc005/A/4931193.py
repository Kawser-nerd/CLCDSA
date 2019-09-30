X = input()

count = 0
s = 0
for x in X:
    if x == 'S':
        s += 1
    elif s > 0:
        s -= 1
        count += 1

print(len(X) - count*2)