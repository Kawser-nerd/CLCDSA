N = int(input())
W = list(input().split())

C = {"b": "1", "c": "1", "d": "2", "w": "2", "t": "3", "j": "3", "f": "4", "q": "4", "l": "5", "v": "5",
     "s": "6", "x": "6", "p": "7", "m": "7", "h": "8", "k": "8", "n": "9", "g": "9", "z": "0", "r": "0"}

ans = []
for word in W:
    tmp = ""
    for w in word.lower():
        if w in C.keys():
            tmp += C[w]
    if tmp:
        ans.append(tmp)

print(" ".join(ans))