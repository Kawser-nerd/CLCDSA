w = list(input())
a = ["a", "i", "u", "e", "o"]
w = [w_ for w_ in w if w_ not in a]
print("".join(w))