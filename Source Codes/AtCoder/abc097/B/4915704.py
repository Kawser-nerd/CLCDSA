X = int(input())
lists = []
max = 1
for i in range(1,X+1):
    for j in range(2,X+1):
        if i**j <= X:
            if max < i**j:
                max = i**j
        elif i**j > X:
            break
print(max)