N,M = map(int,input().split(" "))
list = []
for i in range(N):
    list.append(i+1)
for i in range(N):
    if int(list[i]) != M:
        print(i+1)
        break