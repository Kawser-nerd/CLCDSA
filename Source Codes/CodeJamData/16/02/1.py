t = int(input())

for cs in range(1, t+1):
    s = input()
    result = 0
    for c in reversed(s):
        if (c == '-' and result % 2 == 0):
            result += 1
        elif (c == '+' and result % 2 == 1):
            result += 1
    print("Case #" + str(cs) + ": " + str(result))
