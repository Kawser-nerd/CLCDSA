numbers = input()
position = int(input())
answer = "1"
for num in numbers[:position]:
    if num != "1":
        answer = num
        break
print(answer)