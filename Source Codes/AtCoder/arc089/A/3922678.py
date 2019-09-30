z = int(input())
x = 0
y = 0
t = 0
for i in range(z):
    s,a,b = map(int,input().split(" "))
    if s - t < abs(a-x) + abs(b-y):
        print("No")
        exit()
    elif (s - t) % 2 == 1 and (abs(a-x) + abs(b-y)) % 2 == 0:
        print("No")
        exit()
    elif (s - t) % 2 == 0 and (abs(a-x) + abs(b-y)) % 2 == 1:
        print("No")
        exit()
    else:
        x = a
        y = b
        t = s
print("Yes")