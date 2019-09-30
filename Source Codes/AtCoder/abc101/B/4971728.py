N = input()

sum = 0
for n in N:
    sum += int(n)

if int(N) % sum == 0:
    print('Yes')
else:
    print('No')