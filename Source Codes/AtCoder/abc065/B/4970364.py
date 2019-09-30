n = int(input())
a = []
for i in range(n):
    a.append(int(input())-1)
button = 0 
push = 0
while a[button] != -1:
    push += 1
    tmp = a[button]
    a[button] = -1
    button = tmp 
    if button == 1:
        print(push)
        exit()
print(-1)