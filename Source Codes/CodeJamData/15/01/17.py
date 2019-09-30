T = int( input() )
for t in range(1,T+1):
    N, S = input().split()
    answer, alive, N = 0, int( S[0] ), int(N)
    for n in range(1,N+1):
        if S[n]=='0': continue
        if alive < n:
            answer += n-alive
            alive = n
        alive += int( S[n] )
    print('Case #{}: {}'.format(t,answer))

