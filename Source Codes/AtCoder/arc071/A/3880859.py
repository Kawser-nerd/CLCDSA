N = int(input())
S = [input() for i in range(N)]
ans_set = sorted(S[0])

for k in range(1, N):
    new_set = []
    check_set = sorted(S[k])
    start = -1
    for i in range(len(ans_set)):
        j = start
        while j != len(check_set)-1:
            j += 1
            if ans_set[i] == check_set[j]:
                new_set.append(ans_set[i])
                start = j
                break
    ans_set = new_set

print(''.join(ans_set))