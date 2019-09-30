S = [str(_) for _ in input()]

for i in range(len(S)):
    check = S[i]
    if check == "O" or check == "D":
        S[i] = "0"
    elif check == "I":
        S[i] = "1"
    elif check == "Z":
        S[i] = "2"
    elif check == "S":
        S[i] = "5"
    elif check == "B":
        S[i] = "8"

print("".join(S))