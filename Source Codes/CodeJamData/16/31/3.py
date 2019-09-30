t = int(input())

for i in range(t):
    print("Case #" + str(i + 1) + ":", end = " ")
    n = int(input())
    members = list(map(int, input().split()))
    while max(members) > 0:
        r = max(members)
        l = [i for i in range(len(members)) if members[i] == r]
        if len(l) == 2:
            out = l
        else:
            out = [l[0]]
        print("".join(chr(i + ord('A')) for i in out), end = " ")
        for i in out:
            members[i] -= 1
    print("")
