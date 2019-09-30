N = int(input())
list = [1,2,3,4,5,6,7,8,9]
for i in range(10,100):
    temp = str(i)
    if temp[0] == temp[1]:
        list.append(i)
for i in range(101,1000):
    temp = str(i)
    if temp[0] == temp[1] and temp[1] == temp[2]:
        list.append(i)
for i in range(1001,10000):
    temp = str(i)
    if temp[0] == temp[1] and temp[1] == temp[2] and temp[2] == temp[3]:
        list.append(i)
for i in range(10001,100000):
    temp = str(i)
    if temp[0] == temp[1] and temp[1] == temp[2] and temp[2] == temp[3] and temp[3] == temp[4]:
        list.append(i)
for i in range(100001,1000000):
    temp = str(i)
    if temp[0] == temp[1] and temp[1] == temp[2] and temp[2] == temp[3] and temp[3] == temp[4] and temp[4] == temp[5]:
        list.append(i)

#print(list)
print(list[N-1])