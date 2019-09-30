N,K = map(int,input().split())
schedule = [int(input()) for i in range(N)]

ans = -1

for i in range(2,N) :
    calc = sum(schedule[i-2:i+1])
    if calc < K :
        ans = i+1
        break

print(ans)