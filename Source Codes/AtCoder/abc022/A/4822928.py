N, S, T = map(int,input().split())
W = int(input())
count = 0
if S <= W <=T:
    count += 1    
for _ in range(N-1):
    A = int(input())
    W += A
    if S <= W <=T:
        count += 1  

print(count)