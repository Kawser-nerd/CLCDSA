A,B,C = map(int,input().split())

ans = 0
while not(A%2 or B%2 or C%2):
    A,B,C = B//2+C//2, A//2+C//2, A//2+B//2
    if(A == B == C):
        print(-1)
        exit()
    ans += 1
print(ans)