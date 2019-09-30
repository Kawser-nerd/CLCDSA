N = int(input())

count = [0] * 201
count[105] = 1
for i in range(105, 201):
    if i % 2 == 1:
        num = 0
        for n in range(1, i+1):
            if i % n == 0:
                num += 1
        if num == 8:
            count[i] = count[i-1]+1
        else:
            count[i] = count[i-1]
    else:
        count[i] = count[i-1]

print(count[N])