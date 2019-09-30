N = int(input())
B = list(map(int, input().split(" ")))

l = []
for i in range(N-1, -1, -1):
    for j in range(len(B)-1, -1, -1):
        if B[j] == j+1:
            l.append(j+1)
            B.pop(j)
            break

if len(B) == 0:
    for l_i in l[::-1]:
        print(l_i)
else:
    print(-1)