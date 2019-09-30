listNAB = input().split()
listNABint = [int(s) for s in listNAB]

def Placesum(x):
    y = str(x)
    counter = 0
    for i in range(len(y)):
        counter += int(y[i])
    return counter

sumcounter = 0
for i in range(listNABint[0]):
    if listNABint[1] <= Placesum(i+1) & Placesum(i+1) <= listNABint[2]:
        sumcounter += i+1
print(sumcounter)