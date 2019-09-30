N = int(input())
game = [[""]*N for i in range(9)]
for i in range(N):
    line = input()
    for coun,st in enumerate(line):
        game[coun][i] = st
result = 0
for i in range(9):
    for ii in range(N):
        if game[i][ii] == "x":
            result += 1
        elif game[i][ii] == "o":
            if ii == N-1 or game[i][ii+1] != "o":
                result += 1
print(result)