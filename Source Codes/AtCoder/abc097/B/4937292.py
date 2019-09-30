X = int(input())
list = []
for i in range(1,33):
    for n in range(2,11):
        if i ** n <= X:
            list.append(i ** n)
print(max(list))