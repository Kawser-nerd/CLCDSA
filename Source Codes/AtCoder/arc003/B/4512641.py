N = int(input())
sss = [input()[::-1] for _ in range(N)]

sss.sort()

for ss in sss:
    print(ss[::-1])