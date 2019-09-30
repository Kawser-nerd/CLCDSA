alphabet = {1:"a",2:"b"}
backet = [0]*26
S = input()
for char in S:
    backet[ord(char)-97] = 1
if backet == [1]*26:
    print("None")
else:
    print(chr(backet.index(0)+97))