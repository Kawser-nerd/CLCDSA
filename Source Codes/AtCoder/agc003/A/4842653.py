s=set(list(input()))
if "S" in s:
    if not "N" in s:
        print("No")
        exit()
if "N" in s:
    if not "S" in s:
        print("No")
        exit()
if "E" in s:
    if not "W" in s:
        print("No")
        exit()
if "W" in s:
    if not "E" in s:
        print("No")
        exit()
print("Yes")