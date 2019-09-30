N = int(input())

for cake in range(26):
    flag = False
    for donut in range(15):
        if 4 * cake + 7 * donut == N:
            print('Yes')
            flag = True
            break
    if flag:
        break
    

else:
    print('No')