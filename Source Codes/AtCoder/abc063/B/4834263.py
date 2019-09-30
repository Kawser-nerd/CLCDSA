S = input()
if len(S) == len(set(list(S))):
    print("yes")
else:
    print("no")