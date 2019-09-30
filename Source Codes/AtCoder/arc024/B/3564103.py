N = int(input())
cl = [int(input()) for i in range(N)]
ans = 1
renzoku1 = 1
score = 1
renzoku = 0
for i in range(N):
    if(i == 0):
        if(cl[0] == cl[1]):
            renzoku1 = 2
            renzoku = 1
    elif(renzoku == 1):
        if(i == N-1):
            if(cl[i] == cl[0]):
                print(-1)
            else:
                print(N//2)
            quit()
        if(cl[i] == cl[i+1]):
            renzoku1 += 1
        else:
            renzoku = 0
    elif(renzoku == 0):
        if(i == N-1):
            if(cl[i] == cl[0]):
                score += renzoku1
                ans = max(ans, score)
            else:
                ans = max(score, max(ans, renzoku1))   
        elif(cl[i] == cl[i+1]):
            score += 1
        else:
            ans = max(ans, score)
            score = 1
if(ans == 2):
    print(1)
else:
    print((ans+1)//2)