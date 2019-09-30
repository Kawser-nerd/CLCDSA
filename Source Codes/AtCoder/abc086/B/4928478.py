a, b = input().split()

ab = int(a+b)

for i in range(400):
    if i*i == ab:
        print('Yes')
        exit()


print('No')