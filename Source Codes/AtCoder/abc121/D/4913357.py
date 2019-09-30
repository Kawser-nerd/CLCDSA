A,B = map(int,input().split())

A -= 1

if A % 4 == 1:
    A = 1
elif A % 4 == 2:
    A += 1
elif A % 4 == 3:
    A = 0

if B % 4 == 1:
    B = 1
elif B % 4 == 2:
    B += 1
elif B % 4 == 3:
    B = 0

answer = A^B
print(answer)