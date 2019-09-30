N = int(input())
N1 = 1
N2 = 2
N3 = 4
N4 = 8
ansList = []
if N >= N4:
    ansList.append(N4)
    N -= N4
elif N >= N3:
    ansList.append(N3)
    N -= N3
if N >= N2:
    ansList.append(N2)
    N -= N2
elif N >= N1:
    ansList.append(N1)
    N -= N1
print(len(ansList))
for i in ansList:
    print(i)