s = input()
N = int(input())
cnt = 1
for c1 in s:
    for c2 in s:
        if cnt == N:
            print(c1 + c2)
        cnt += 1