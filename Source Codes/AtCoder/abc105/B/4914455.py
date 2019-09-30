N = int(input())

for cake in range(26):
    for donut in range(15):
        if 4 * cake + 7 * donut == N:
            print('Yes')
            exit()

else:
    print('No')