N = input()
l = [int(x) for x in list(N)]

l = set(l)

if len(l) == 1:
    print("SAME")
else:
    print("DIFFERENT")