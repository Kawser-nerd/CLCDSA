a = list(input())
a = [int(x) for x in a]

a2 = [1 if i == 9 else 9 for i in a]

for i in range(len(a2)):
    print(a2[i], end="")