alp = "abcdefghijklmnopqrstuvwxyz"
for c in list(input()):
    alp = alp.replace(c, "")
print(alp[0] if len(alp) else "None")