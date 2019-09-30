S = input()
N = int(input())

if N <= 5:
    print(S[0] + S[N - 1])
elif N <= 10:
    print(S[1] + S[N - 6])
elif N <= 15:
    print(S[2] + S[N - 11])
elif N <= 20:
    print(S[3] + S[N - 16])
else:
    print(S[4] + S[N - 21])