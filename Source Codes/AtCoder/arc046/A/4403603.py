N = int(input())

res = 0
for i in range(10 ** 6):
    tmp = str(i)[0]
    flag = True
    for j in range(len(str(i))):
        if tmp != str(i)[j]:
            flag = False
            break
        
    if flag == True:
        res += 1
        
    if res == N+1:
        print(i)
        break