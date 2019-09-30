S = set(list(input()))
if len(S) == 4: print("Yes")
elif len(S) == 2:
    if S == {"N", "S"} or S == {"E", "W"}: print("Yes")
    else:print("No")
else: print("No")