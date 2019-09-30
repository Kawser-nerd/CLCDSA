a, b = list(map(int, input().split()))
num = []
for n in range(a,b+1):
    num.append(str(n))
count = 0
for i in range(len(num)):
    hantei = 0
    for j in range(len(num[i])//2):
        if num[i][j] == num[i][-(j+1)]:
            #print(num[i][j],num[i][-(j+1)],num[i])
            hantei += 1
    if hantei == len(num[i])//2:
        count += 1
print(count)