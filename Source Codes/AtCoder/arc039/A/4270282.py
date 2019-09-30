A,B = map(int,input().split(" "))
listA = []
listB = []
ans = []
for k in range(3):
    for i in range(10):
        if k == 0 and i == 0:
            pass
        else:
            T = list(str(A))
            T[k] = str(i)
            #print(T)
            temp = ""
            for j in range(3):
                temp += T[j]
            listA.append(temp.rstrip())
#print(listA)
for i in range(len(listA)):
    ans.append(int(listA[i]) - B)

for k in range(3):
    for i in range(10):
        if k == 0 and i == 0:
            pass
        else:
            T = list(str(B))
            T[k] = str(i)
            #print(T)
            temp = ""
            for j in range(3):
                temp += T[j]
            listB.append(temp.rstrip())
#print(listB)
for i in range(len(listB)):
    ans.append(A - int(listB[i]))
print(max(ans))