A, B, C = map(int, input().split())

sumA = 0
i = 1
ans = False

while sumA <= A * B + C :
    sumA += i * A
    if sumA % B == C :
        ans = True
        break
    #i += 1

if ans == True :
    print('YES')
else :
    print('NO')