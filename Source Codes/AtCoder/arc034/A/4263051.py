N = int(input())
a = []
for i in range(N):
    temp = input().split(" ")
    temp = [int(i) for i in temp]
    total = 0
    #print(temp)
    for j in range(4):
        total += temp[j]
    #print(total)
    total += temp[4]*110/900
    a.append(total)
#print(a)
print(max(a))