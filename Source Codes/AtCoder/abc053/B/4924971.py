S = input()
head = 0
end = 0

for i in range(len(S)):
    if S[i] == "A":
        head = i
        break

for i in range(len(S) - 1, -1, -1):
    if S[i] == "Z":
        end = i + 1
        break

print(end - head)