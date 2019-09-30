S = list(input())
List = []
key = 0
for i in range(len(S)):
    times = 1
    if S[i] == '*':
        S[i] = 1
    elif i == len(S)-1:
        for j in S[key:]:
            times = times*int(j)
        List.append(times)
    elif S[i] == '+':
        for j in S[key:i]:
            times = times*int(j)
        List.append(times)
        key = i+1
count = 0
for i in List:
    if i != 0:
        count += 1
print(count)