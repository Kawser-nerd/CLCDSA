N = int(input())

before = []
answer = 'Yes'

for i in range(N):
    s = input()
    if s in before:
        answer = 'No'
    if len(before) > 0:
        if before[-1][-1] != s[0]:
            answer = 'No'

    before.append(s)

print(answer)