S = input()

counter = 0
ans = 0

for index, char in enumerate(S):
    if(char == "W"):
        ans += index - counter
        counter += 1

print(int(ans))