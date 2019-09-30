k = int(input())

n = 50

a = k//n
b = k%n

if b == 0:
    res = [a]*n
    for i in range(n):
        res[i] += i
else:
    res = [0]*(n+1)
    for i in range(n+1):
        res[i] = i
    del res[n-b]
    for i in range(n):
        res[i]+=a
print(n)
ass = ''
for i in range(n):
    if i != 0:
        ass += ' '
    ass += str(res[i])
print(ass)