n = input()
s = input()
ltmp = 0
ladd = 0
for c in s:
    if c == ")":
        if ltmp == 0:
            ladd += 1
        else:
            ltmp -= 1
    else:
        ltmp += 1
        
print("(" * ladd + s + ")" * ltmp)