N = int(input()); r = input()
tmp = 0
for i in range(N):
    if r[i] == 'A':
        tmp += 4
    elif r[i] == 'B':
        tmp += 3
    elif r[i] == 'C':
        tmp += 2
    elif r[i] == 'D':
        tmp += 1
print(tmp / N)