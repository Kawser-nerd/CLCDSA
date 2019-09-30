w = list(map(str,input()))

while "a" in w:
    w.remove("a")
while "e" in w:
    w.remove("e")
while "i" in w:
    w.remove("i")
while "o" in w:
    w.remove("o")
while "u" in w:
    w.remove("u")

print("".join(w))