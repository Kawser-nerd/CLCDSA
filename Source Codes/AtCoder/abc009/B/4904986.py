n=input()
list=[]
for i in range(int(n)):
    temp=input()
    list.append(int(temp))

list.sort()

for i in reversed(range(len(list))):
    if list[i]==list[i-1]:
        continue
    else:
        print(list[i-1])
        break