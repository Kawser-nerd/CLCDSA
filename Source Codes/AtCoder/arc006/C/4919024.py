n = int(input())
w = []
for _ in range(n):
    w.append(int(input()))

room = [w[0]]
w.pop(0)
for wi in w:
    num = 0
    for i in range(len(room)):
        if (wi <= room[i]):
            room[i] = wi
            break
        else:
            num += 1
    if (len(room) == num):
        room.append(wi)
    
print(len(room))