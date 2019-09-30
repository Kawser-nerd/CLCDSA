N = int(input())
S = input()
if N % 2 == 0:
    print(-1)
else:
    begin = S[: int((N - 1) / 2)]
    middle = S[int((N - 1) / 2)]
    end = S[int((N + 1) / 2) :]
    if middle != 'b':
        print(-1)
    else:
        i = 0
        while i < len(begin):
            if i % 3 == 0:
                if begin[-i-1] == 'a' and end[i] == 'c':
                    i += 1
                else:
                    print(-1)
                    break
            elif i % 3 == 1:
                if begin[-i-1] == 'c' and end[i] == 'a':
                    i += 1
                else:
                    print(-1)
                    break
            else:
                if begin[-i-1] == 'b' and end[i] == 'b':
                    i += 1
                else:
                    print(-1)
                    break
        if i == len(begin):
            print(i)