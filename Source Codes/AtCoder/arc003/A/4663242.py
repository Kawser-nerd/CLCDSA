n=int(input())
r=input()
 
score = 0
for i in range(n):
    if r[i] == 'A':
        score += 4
    elif r[i] == 'B':
        score += 3
    elif r[i] == 'C':
        score += 2
    elif r[i] == 'D':
        score += 1
 
print(score/n)