S = input()
N = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
id = []
for i in S:
    if i in N:
        id.append(i)
print(''.join(id))