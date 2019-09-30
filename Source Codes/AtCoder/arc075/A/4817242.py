N = int(input())
S = [int(input()) for _ in range(N)]

score = {0}
for s in S:
    tmp = set()
    for i in score:
        tmp.add(s+i)  
    score |= tmp
for i in range(10,10010,10):
    if i in score:               
        score.remove(i)
print(max(score))