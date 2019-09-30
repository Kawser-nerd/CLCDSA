f = open('C:\\Users\\djspence\\Downloads\\B-large.in', 'r')

tries = int(f.readline())

for i in range(0, tries):
    pans = f.readline().strip()
    flips = 0
    for j in range(1, len(pans)):
        if pans[j] != pans[j - 1]:
            flips += 1
    if pans[len(pans) - 1] == "-":
        flips += 1
    print("Case #" + str(i + 1) + ": " + str(flips))