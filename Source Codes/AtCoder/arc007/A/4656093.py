X = input()
s = [str(_) for _ in input()]
Res = []

for i in s:
    if X == i:
        continue
    else:
        Res.append(i)
print("".join(Res))