S = input()
if "N" in S and "S" in S:
    if ("W" in S and "E" in S) or ("W" not in S and "E" not in S):
        print("Yes")
    else:
        print("No")
elif "N" in S or "S" in S:
    print("No")
else:
    if "W" in S and "E" in S:
        print("Yes")
    else:
        print("No")