# 2019/04/12
# AtCoder Beginner Contest 097 - B

b = int(input())
max = 0

for i in range(1, 33):
    for j in range(2, 11):
        val = i**j
        if val > b:
            break
        
        if max < val:
            max = val

print(max)