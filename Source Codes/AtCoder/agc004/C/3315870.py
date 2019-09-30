H, W = map( int, input().split())
V = [ input() for _ in range(H)]
B = [ '' for _ in range(H)]
R = [ '' for _ in range(H)]
N = '#'*(W-1)
for i in range(H):
    if i%2 == 0:
        B[i] = N+V[i][-1]
        R[i] = V[i][:W-1] + '#'
    else:
        R[i] = V[i][-1] + N
        B[i] = '#' + V[i][1:]
for i in range(H):
    print(B[i])
print('')
for i in range(H):
    print(R[i])