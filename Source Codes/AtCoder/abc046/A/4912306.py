a ,b ,c = map(int, input().split())

x = [a, b, c]
y = []
for i in x:
    if i not in y:
        y.append(i)

print(int(len(y)))