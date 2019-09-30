sums = [1]  # pair number sum until index
csums = {}  # pair number sum of each color

N = int(input())
C = []      # color stone list
lastc = -1  # last color of input
for i in range(N):
    c = int(input())
    if(lastc == c):
        continue
    lastc = c
    C.append(c)

#print("C = " + str(C))

for i, c in enumerate(C, 1):
    if(c in csums):
        sums.append(sums[-1] + csums[c])
        csums[c] += sums[i - 1]
    else:
        sums.append(sums[-1])
        csums[c] = sums[i - 1]

#    print("i = {}, c = {}".format(i, c))
#    print("csums = " + str(csums))
#    print("sums = " + str(sums))

print(sums[-1] % (10 ** 9 + 7))