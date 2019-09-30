n = int(input())
li_b = list()

for i in range(n - 1):
    li_b.append((i + 2, int(input())))


def dp(no):

    buka_saralys = [dp(b[0]) for b in li_b if b[1] == no]

    if len(buka_saralys) == 0:
        return 1
    else:
        return max(buka_saralys) + min(buka_saralys) + 1


answer = dp(1)
print(answer)