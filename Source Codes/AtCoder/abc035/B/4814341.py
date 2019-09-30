order = input()
T = int(input())
order_list = list(order)
count = 0
position = [0,0]

for n in order_list:
    if n == "L":
        position[0] -= 1
    elif n == "R":
        position[0] += 1
    elif n == "U":
        position[1] += 1
    elif n == "D":
        position[1] -= 1
    elif n == "?":
        count += 1

if T == 1:#max
    print(abs(position[0]) + abs(position[1]) + count)
elif T == 2: #min
    if abs(position[0]) + abs(position[1]) >= count:
        print(abs(position[0]) + abs(position[1]) - count)
    else:
        if (abs(position[0]) + abs(position[1]) - count) % 2 == 0:
            print(0)
        else:
            print(1)