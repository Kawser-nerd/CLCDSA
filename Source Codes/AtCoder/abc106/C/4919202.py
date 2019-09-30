S = input()
K = int(input())

count1 = 0
for i in S:
    if i == '1':
        count1 += 1
        if K == count1:
            print(i)
            quit()
    else:
        print(i)
        quit()