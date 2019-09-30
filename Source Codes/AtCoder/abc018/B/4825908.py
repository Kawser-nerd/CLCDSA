S = "S" + input() + "E"
N = int(input())
for _ in range(N):
    l, r = map(int, input().split())
    if l == 1:
        S1 = ''
    else:
        S1 = S[1:l]

    if r == len(S)-2:
        S3 = ''
    else:
        S3 = S[r+1:len(S)-1]
    S2 = S[r:l-1:-1]
    S = "S" + S1 + S2 + S3 + "E"    
print(S[1:len(S)-1])