import sys

N = int(input())
judge = []
for i in range(N):
    W = input()
    if W in judge:
        print('No')
        sys.exit()
    else:
        if not judge:
            judge.append(W)
        else:
            if judge[-1][-1] != W[0]:
                print('No')
                sys.exit()
            else:
                judge.append(W)

print('Yes')