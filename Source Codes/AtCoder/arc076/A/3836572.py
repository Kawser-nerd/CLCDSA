a,b = map(int,input().split(" "))
c = 1
d = 1
for i in range(2,a+1):
    c = (c * i) % (10 ** 9 + 7)
for i in range(2,b+1):
    d = (d * i) % (10 ** 9 + 7)
if abs(a - b) >= 2:
    print(0)
elif a == b:
    print(((c * d) * 2) % (10 ** 9 + 7))
else:
    print((c * d) % (10 ** 9 + 7))