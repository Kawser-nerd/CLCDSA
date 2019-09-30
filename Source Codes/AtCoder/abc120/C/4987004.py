S = list(input())

prev = ""
index = 0
ans = 0
while index < len(S):
#    print("index[{}] S[{}]".format(index, S))
    if prev == "":
        prev = S[index]
        index = index + 1
        continue

    if S[index] != prev:
        S.pop(index)
        S.pop(index - 1)
        ans = ans + 2
        if len(S) == 0:
            break

        index = index - 2 if index - 2 > 0 else 0
        prev = ""

    else:
        prev = S[index]
        index = index + 1

print(ans)