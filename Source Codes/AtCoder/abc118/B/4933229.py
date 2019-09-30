N, M = map(int, input().split())
likeset = set(range(1, M+1)) 
for _ in range(N):
    a, *b = map(int, input().split()) 
    likeset &= set(b) 
print(len(likeset))