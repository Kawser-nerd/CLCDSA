N = int(input())

play = [["" for i in range(N)] for i in range(9)]

for i in range(N):
    X = input()
    for j in range(9):
        play[j][N-i-1] = X[j:j+1]

#number of "x"
countx = 0

for i in range(9):
    for j in range(N):
        if play[i][j] == "x":
            countx += 1

#number of "o"s 
counto = 0
for i in range(9):
    waso = False
    for j in range(N):
        
            
        #count "o"s
        if play[i][j] == "o":
            if waso:
                continue
            else:
                counto += 1
            waso = True
            
        else:
            waso = False
        
count = countx + counto

print(count)