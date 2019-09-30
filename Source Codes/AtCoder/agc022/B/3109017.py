N = int(input())
s = 0
L = []
a=2
for i in range(N-2):
    while not (a%2==0 or a%3==0 or a%5==0):
        a += 1
    L.append(a)
    s += a
    a += 1
while (not (a%2==0 or a%3==0 or a%5==0)) or (not ((a + s) % 2 == 0 or (a + s) % 3 == 0 or (a + s) % 5 == 0)):
    a += 1
if (a+s)%2 == 0:
    m=2
elif (a+s)%3 == 0:
    m=3
else:
    m=5
L.append(a)
s += a
a = a//m * m + m
while (a+s)%30!=0:
    a += m
L.append(a)
print(" ".join(map(str, L)))