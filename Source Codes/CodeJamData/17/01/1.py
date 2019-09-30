t = int(input())

for tc in range(1, t + 1):
    print("Case #" + str(tc) + ": ", end = "")
    line, k = input().strip().split()
    k = int(k)
    line = [c == "+" for c in line]
    r = 0
    for i in range(len(line) - k + 1):
        if not line[i]:
            r += 1
            for j in range(k):
                line[i+j] = not line[i+j]
    if all(line):
        print(r)
    else:
        print("IMPOSSIBLE")
